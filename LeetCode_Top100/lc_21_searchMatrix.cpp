//
// Created by apple on 2024/10/20.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || target < matrix[0][0]) return false;
    int i = 0, j = static_cast<int>(matrix[0].size() - 1);
    while (i < matrix.size() && j >= 0) {
      if (matrix[i][j] == target) {
        return true;
      }
      if (matrix[i][j] > target){
        --j;
      }else {
        ++i;
      }
    }
    return false;
  }
};

int main(int argc, char** argv) {
  Solution s;
  vector<vector<int>> test = {{1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  cout << s.searchMatrix(test, 4);

  return 0;
}