#include <string>
#include <regex>
#include <iostream>

#include <regex>

using namespace std;

class EightiesKids5
{
public:
    static string bucketOf(const string &words);
};

string EightiesKids5::bucketOf(const string &words) {
    string bucketFill{"air"};

    regex forbiddenWordsWater(".*(water|wet|wash).*", regex_constants::icase);
    smatch matchedResultsWater;
    regex_search(words, matchedResultsWater, forbiddenWordsWater);
    if (!matchedResultsWater.empty()) {
        bucketFill = "water";
    }

    regex forbiddenWordsSlime(".*(I don'?t know|slime).*", regex_constants::icase);
    smatch matchedResultsSlime;
    regex_search(words, matchedResultsSlime, forbiddenWordsSlime);
    if (!matchedResultsSlime.empty()) {
        bucketFill = "slime";
    }

    regex_search(words, matchedResultsWater, forbiddenWordsWater);
    regex_search(words, matchedResultsSlime, forbiddenWordsSlime);
    if (!matchedResultsWater.empty() && !matchedResultsSlime.empty()) {
        bucketFill = "sludge";
    }

    return bucketFill;
}

int main() {
    auto result = EightiesKids5::bucketOf("asdf");
    std::cout << result << std::endl;

    result = EightiesKids5::bucketOf("water");
    std::cout << result << std::endl;

    result = EightiesKids5::bucketOf("WATER");
    std::cout << result << std::endl;

    result = EightiesKids5::bucketOf("some \n WATER");
    std::cout << result << std::endl;

    result = EightiesKids5::bucketOf("slime");
    std::cout << result << std::endl;

    result = EightiesKids5::bucketOf("water slime");
    std::cout << result << std::endl;
}
