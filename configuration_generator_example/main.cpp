#include "DID.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

int main() {
    //example();

    //std::string filename = "C:\\Users\\admin\\Documents\\didar_ambient_conditions_did_list.csv";
    std::string filename = "C:\\Users\\admin\\Documents\\DiDaR-CR-Template-extract_with_added_names.csv";

    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string didEntry;
    std::vector<std::unique_ptr<DID>> dids;
    while(getline(buffer, didEntry)){ // read data from file object and put it into string
        std::string partOfTokenizedString;
        std::stringstream didEntryStream {didEntry};
        std::vector <std::string> tokens;
        while(getline(didEntryStream, partOfTokenizedString, ';')) {
            tokens.emplace_back(partOfTokenizedString);
        }

        if (tokens.size() < 4) {
            continue;
        }

        std::string didID = tokens.at(0);
        std::string didName = tokens.at(1);
        std::string didLengthInBytes = tokens.at(2);
        std::string didA2L_Element = tokens.at(3);

        auto did = std::make_unique<DID>(
            didID,
            didName,
            didLengthInBytes,
            didA2L_Element);
        dids.emplace_back(std::move(did));

        didID.clear();
        didName.clear();
        didLengthInBytes.clear();
        didA2L_Element.clear();
    }

    for (const auto& did : dids) {
        std::cout << *did << '\n';
    }

    std::ofstream generatedDID_lines("pregenerated_lines_for_DIDs_matching_criteria.txt");
    for (const auto& did : dids) {
        generatedDID_lines << *did << '\n';
    }

    return 0;
}
