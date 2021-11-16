#include <iostream>

#include <string>
#include <sstream>
#include <climits>

void updateHighestNumber(int& highestNumber, int currentNumber);
void updateLowestestNumber(int& lowestNumber, int currentNumber);

std::string highAndLow(const std::string& numbers){
  int highestNumber = INT_MIN;
  int lowestNumber = INT_MAX;

  std::stringstream convertedNumbers(numbers);
  int currentNumber{};

  while(convertedNumbers >> currentNumber){
    updateHighestNumber(highestNumber, currentNumber);
    updateLowestestNumber(lowestNumber, currentNumber);
  }

  std::stringstream result;
  result << highestNumber << " " << lowestNumber;
  return result.str();
}

void updateHighestNumber(int& highestNumber, int currentNumber){
  if (currentNumber > highestNumber){
    highestNumber = currentNumber;
  }
}

void updateLowestestNumber(int& lowestNumber, int currentNumber){
  if (currentNumber < lowestNumber){
    lowestNumber = currentNumber;
  }
}

int main() {
    std::cout << highAndLow("1 2 3 4 5") << std::endl;
    std::cout << highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4") << std::endl;
    return 0;
}