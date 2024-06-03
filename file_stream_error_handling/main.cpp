#include <cstring>
#include <fstream>
#include <iostream>

bool checkFileStatus(std::ofstream& outputFile) {
    if (outputFile.rdstate() == std::ios_base::failbit) {
        std::cerr << "openFileStream: unable to open file: " << strerror(errno) << std::endl;
        return false;
    }

    if (!outputFile.is_open()) {
        std::cerr << "openFileStream: unable to open file: " << strerror(errno) << std::endl;
        return false;
    }

    std::cout << "openFileStream: the file had been opened correctly." << std::endl;
    outputFile.clear(); // clear error state indicator (binary mask: 'goodbit', 'failbit', etc.)
    return true;
}

int main() {
    std::string outputFileName{"outputFile.txt"};
    std::ofstream outputFile;
    outputFile.open(outputFileName, std::ios_base::out | std::ios_base::app);
    auto fileOpeningStatus = checkFileStatus(outputFile);
    std::cout << "fileOpeningStatus = " << fileOpeningStatus << std::endl;
    return 0;
}
