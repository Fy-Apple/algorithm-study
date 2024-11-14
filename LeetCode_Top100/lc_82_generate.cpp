//
// Created by apple on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    for (int i = 0; i < numRows; ++i) {
      result.emplace_back();
      for (int j = 0; j <= i; ++j) {
        if (j == 0 || j == i) result[i].emplace_back(1);
        else if (j > 0 && j < i) result[i].emplace_back(result[i - 1][j - 1] + result[i - 1][j]);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  for (auto v : s.generate(5)) {
    cout << "[";
    for (auto num : v) {
      cout << num << ", ";
    }
    cout << "], ";
  }

  return 0;
}