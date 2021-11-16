#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

struct Journal {
    std::string title;
    std::vector<std::string> entries;

    explicit Journal(std::string title) : title(std::move(title)) {}

    void addEntry(const std::string& entry) {
        static int count = 1;
        std::stringstream finalEntry;
        finalEntry << count;
        finalEntry << ": ";
        finalEntry << entry;
        entries.emplace_back(finalEntry.str());
        count++;
    }

    void show() {
        for (const auto& entry : entries) {
            std::cout << entry << std::endl;
        }
    }
};

struct PersistenceManager {
    // All persistence code in one place
    // instead of scattering it through the specific objects.
    // This centralization makes the persistence feature easier to refactor and reuse
    static void save(const Journal& journal, const std::string& filename) {
        std::ofstream ofs(filename);

        for (const auto& entry : journal.entries) {
            ofs << entry << std::endl;
        }
    }
};

int main() {
    Journal journal{"Diary"};

    journal.addEntry("I ate a bug");
    journal.addEntry("I cried today");

    journal.show();

//    journal.save("diary.txt");

    PersistenceManager persistenceManager;
    persistenceManager.save(journal, "diary.txt");

    return 0;
}