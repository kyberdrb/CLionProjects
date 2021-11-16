#include <iostream>
#include <climits>

#include <vector>
#include <algorithm>
#include <cstdint>

namespace Triangle
{
  bool isAnyOfTriangleSidesNegative(int, int, int);
  std::vector<uint32_t> sortSidesAscendingly(int, int, int);
  bool isTriangleInequalityTrue(std::vector<uint32_t>);

  bool isTriangle(int a, int b, int c)
  {
    if (isAnyOfTriangleSidesNegative(a, b, c)) {
      return false;
    }

    std::vector<uint32_t> triangleSides = sortSidesAscendingly(a, b, c);
    return isTriangleInequalityTrue(triangleSides);
  }

  bool isAnyOfTriangleSidesNegative(int a, int b, int c)
  {
    return a <= 0 || b <= 0 || c <= 0;
  }

  std::vector<uint32_t> sortSidesAscendingly(int a, int b, int c)
  {
    uint32_t side_a = a;
    uint32_t side_b = b;
    uint32_t side_c = c;
    std::vector<uint32_t> triangleSides{side_a, side_b, side_c};
    std::sort(triangleSides.begin(), triangleSides.end());
    return triangleSides;
  }

  bool isTriangleInequalityTrue(std::vector<uint32_t> triangleSides)
  {
    uint32_t sumOfFirstTwoSmallestSides = triangleSides.at(0) + triangleSides.at(1);
    uint32_t& longestSide = triangleSides.at(2);
    return sumOfFirstTwoSmallestSides > longestSide;
  }
};

int main() {
  std::cout << Triangle::isTriangle(INT_MAX,INT_MAX,INT_MAX) << std::endl;
  return 0;
}