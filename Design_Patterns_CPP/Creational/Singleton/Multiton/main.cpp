#include <iostream>
#include <map>
#include <memory>

template <typename T, typename Key = std::string>
class Multiton {
private:
    static std::map<Key, std::shared_ptr<T>> instances;

protected:
    // protected fields are optional.
    // they serve mainly for inheritance purposes.
    Multiton() = default;
    virtual ~Multiton() = default;

public:
    static std::shared_ptr<T> get(const Key& key) {
        if (const auto it = instances.find(key); it != instances.end()) {
            return it->second;
        }

        auto instance = std::make_shared<T>();
        instances[key] = instance;
        return instance;
    }
};

template <typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

class Printer {
public:
    Printer() {
        ++instanceCount;
        std::cout <<
            "A total of " <<
            Printer::instanceCount <<
            " instances created so far" << std::endl;
    };

private:
    static int instanceCount;
};

int Printer::instanceCount = 0;

enum Importance {
    primary,
    secondary,
    tertiary
};

int main() {
    typedef Multiton<Printer, Importance> mt;
    std::shared_ptr<Printer> main = mt::get(Importance::primary);
    std::shared_ptr<Printer> aux1 = mt::get(Importance::secondary);
    std::shared_ptr<Printer> aux2 = mt::get(Importance::secondary);
    return 0;
}