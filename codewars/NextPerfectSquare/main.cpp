#include <iostream>

#include <cmath>

bool isSquareImperfect(long double);

long int findNextSquare(long int sq) {
  long double currentBase = sqrt(sq);

  if (isSquareImperfect(currentBase)) {
    return -1;
  }

  long double nextBase = floor(currentBase) + 1;
  return pow(nextBase, 2);
}

bool isSquareImperfect(long double base) {
  long double remainder = base - floor(base);
  return remainder > 0;
}

int main() {
  std::cout << findNextSquare(121) << std::endl;
  return 0;
}