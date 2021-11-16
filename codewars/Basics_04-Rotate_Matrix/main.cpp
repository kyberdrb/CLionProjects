#include <iostream>

#include <vector>

std::vector<std::vector<int>> rotateMatrixLeft(std::vector<std::vector<int>> matrix)
{
    int originalNumberOfRows = matrix.size();
    int originalNumberOfColumns = matrix[0].size();

    int& targetNumberOfRows = originalNumberOfColumns;
    int& targetNumberOfColumns = originalNumberOfRows;

    std::vector<std::vector<int>> leftRotatedMatrix(targetNumberOfRows, std::vector<int>(targetNumberOfColumns));

    int targetRow{};
    int lastColumnIndex = originalNumberOfColumns - 1;
    for(int column = lastColumnIndex; column >= 0; --column) {
        for(int row = 0; row < originalNumberOfRows; ++row) {
            int& targetColumn = row;
            leftRotatedMatrix[targetRow][targetColumn] = matrix[row][column];
        }

        ++targetRow;
    }

    return leftRotatedMatrix;
}

void printMatrix(std::vector<std::vector<int>> matrix) {
    for (int row = 0; row < matrix.size(); ++row) {
        for (int column = 0; column < matrix[0].size(); ++column) {
            std::cout << matrix[row][column] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
  std::vector<std::vector<int>> matrix =
      {
          { -1, 1, 5 },
          { 2, 3, 4 },
      };

  printMatrix(matrix);

  std::vector<std::vector<int>> actual = rotateMatrixLeft(matrix);

  std::cout << std::endl;

  printMatrix(actual);

  return 0;
}