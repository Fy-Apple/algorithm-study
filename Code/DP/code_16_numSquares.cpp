//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"

#include <valarray>
// 279. 完全平方数
class Solution {
public:
  int numSquares(int n) {
    const int size = static_cast<int>(sqrt(n));
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= size; ++i) {
      for (int j = i * i; j <= n; ++j) {
        dp[j] = min(dp[j], dp[j - i * i] + 1);
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.numSquares(13);
  return 0;
}
