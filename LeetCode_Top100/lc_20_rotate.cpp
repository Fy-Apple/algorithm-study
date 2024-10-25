//
// Created by apple on 2024/10/20.
//

#include <array>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.size() <= 1) return;
    int loopNum = static_cast<int>(matrix.size() / 2) + 1;
    int indexI = 0, indexJ = 0;

    //row1, col1  ->  col1, size - row1 - 1
    int swapNum = static_cast<int>(matrix.size()) + 1;
    while (--loopNum) {
      swapNum -= 2;
      int i = -1;
      while (++i < swapNum) {
          const int temp = matrix[indexI][indexJ + i];
          matrix[indexI][indexJ + i] = matrix[matrix.size() - 1 - indexJ - i][indexI];
          matrix[matrix.size() -1 - indexJ - i][indexI] = matrix[matrix.size() - 1 - indexI][matrix.size() -1 - indexJ - i];
          matrix[matrix.size() - 1 - indexI][matrix.size() -1 - indexJ - i] = matrix[indexJ + i][matrix.size() - 1 - indexI];
          matrix[indexJ + i][matrix.size() - 1 - indexI] = temp;
      }
      ++indexI;
      ++indexJ;
    }
  }
};

int main(int argc, char** argv) {
  Solution s;
  vector<vector<int>> test = {{5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(test);
  for (const auto& v : test) {
    for (const auto& num : v) {
      cout << num << ", ";
    }
    cout << endl;
  }

  return 0;
}