//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int value = 0;
    result[0][0] = ++value;
    int top = 1, bottom = n, left = 0, right = n;
    int i = 0, j = 0;
    while (true) {
      while (j + 1 < right) {
        ++j;
        result[i][j] = ++value;
      }
      -- right;
      while (i + 1 < bottom) {
        ++i;
        result[i][j] = ++value;
      }
      --bottom;
      while (j - 1 >= left) {
        --j;
        result[i][j] = ++value;
      }
      ++left;
      while (i - 1 >= top) {
        --i;
        result[i][j] = ++value;
      }
      ++top;
      if (value == n * n) break;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {


  return 0;
}
