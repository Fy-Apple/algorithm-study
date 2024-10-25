//
// Created by apple on 2024/10/20.
//

#include <array>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return  result;
    if (matrix.size() == 1) return  matrix[0];

    int i = 0, j = 0;
    int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
    int direct = 0;
    int numSize = static_cast<int>(matrix.size() * matrix[0].size());
    for (int number = 0; number < numSize;) {
      result.push_back(matrix[i][j]);
      ++number;

      if (direct == 0) {
        // 右走
        if ( j < right) {
          ++j;
        }else {
          ++i;
          --right;
          direct = 1;
        }
      }else if (direct == 1) {
        // 下走
        if ( i < bottom) {
          ++i;
        }else {
          --j;
          --bottom;
          direct = 2;
        }
      }else if (direct == 2) {
        // 左走
        if ( j > left) {
          --j;
        }else {
          --i;
          ++left;
          direct = 3;
        }
      } else {
        // 上走
        if ( i > top + 1) {
          --i;
        }else {
          ++j;
          ++top;
          direct = 0;
        }
      }
    }
    return  result;
  }
};

int main(int argc, char** argv) {
  Solution s;
  vector<vector<int>> test = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
  for (const auto& num :  s.spiralOrder(test)) {
    cout << num << ", ";
  }

  return 0;
}