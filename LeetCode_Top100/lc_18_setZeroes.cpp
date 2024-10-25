//
// Created by apple on 2024/10/20.
//

#include <array>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    const int r = static_cast<int>(matrix.size());
    const int c = static_cast<int>(matrix[0].size());
    vector<bool> cVec(c, false);

    for (int i = 0; i < r; ++i) {
      int j = 0;
      bool edit = false;
      while (j < c) {
        if (j != c && matrix[i][j] == 0) {
          cVec[j] = true;
          edit = true;
        }
        ++j;
      }
      if (edit) {
        for (int k = 0; k < c; ++k) {
          matrix[i][k] = 0;
        }
      }
    }

    for (int j = 0; j < c; ++j) {
      if (cVec[j]) {
        for (int i = 0; i < r; ++i)
          matrix[i][j] = 0;
      }
    }
  }
};

int main(int argc, char** argv) {
  Solution s;
  vector<vector<int>> test = {{0,0,0,5},{4,3,1,4},{0,1,1,4}, {1,2,1,3}, {0,0,1,1}};
  s.setZeroes(test);
  for (const auto& v : test) {
    for (const auto& num : v) {
      cout << num << ", ";
    }
    cout << endl;
  }

  return 0;
}