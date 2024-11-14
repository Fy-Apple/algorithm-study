//
// Created by apple on 2024/10/28.
//
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0, right = matrix.size() * matrix[0].size() - 1;
    int col = matrix[0].size();
    while (left <= right) {
      int mid = (left + right) / 2;
      if (matrix[mid / col][mid % col] == target) return true;
      if (matrix[mid / col][mid % col] < target) left = mid + 1;
      else right = mid - 1;
    }
    return false;
  }
};


int main(int argc, char *argv[]) {
  vector<vector<int>> test = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  Solution s;
  cout << s.searchMatrix(test, 3);
  return 0;
}
