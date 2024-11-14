//
// Created by apple on 2024/10/30.
//
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int numSquares(int n) {
    vector<int> f(n + 1, 0);
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
      f[i] = f[i - 1] + 1;
      for (int j = 2; j <= sqrt(i); ++j) {
        f[i] = min(f[i], f[i - j * j] + 1);
      }
    }
    return f[n];
  }
};
int main(int argc, char* argv[]) {
  Solution s;
  cout << s.numSquares(12);

  return 0;
}