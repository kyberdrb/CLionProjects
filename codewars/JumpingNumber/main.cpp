#include <iostream>

#include <string>
#include <sstream>

using namespace std;

bool isDigitsDifferenceDistinctFromOne(char first, char second);

string jumpingNumber (int number)
{
    stringstream digits;
    digits << number;

    bool isSingleDigitNumber = digits.str().length() == 1;
    if (isSingleDigitNumber) {
        return "Jumping!!";
    }

    char previousDigit = digits.get();
    char nextDigit{};

    // Why I can put the stream inside the while loop condition?
    //  http://www.augustcouncil.com/~tgibson/tutorial/iotips.html#embed
    //  https://stackoverflow.com/questions/3603047/find-the-end-of-stream-for-cin-ifstream/3603120#3603120
    //  Beacuse at the end of the stream the stream return "nullptr"
    while (digits.get(nextDigit)) {
        bool isJumpingRuleViolated = isDigitsDifferenceDistinctFromOne(previousDigit, nextDigit);
        if (isJumpingRuleViolated) {
            return "Not!!";
        }

        previousDigit = nextDigit;
    }

    return "Jumping!!";
}

bool isDigitsDifferenceDistinctFromOne(char first, char second) {
    char difference = abs(first - second) == 1;
    return difference == 0 || difference > 1;
}

int main() {
    std::cout << jumpingNumber(9) << "\n" << std::endl;
    std::cout << jumpingNumber(32) << "\n" << std::endl;
    std::cout << jumpingNumber(79) << "\n" << std::endl;
    std::cout << jumpingNumber(8987) << "\n" << std::endl;
    std::cout << jumpingNumber(8986) << "\n" << std::endl;
    return 0;
}