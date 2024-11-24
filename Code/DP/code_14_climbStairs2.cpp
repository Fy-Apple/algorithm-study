//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

// 卡吗57
class Solution {
public:
  int climb(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if(i >= j) dp[i] += dp[i - j];
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int m, n;
  cin >> n >> m;
  cout << s.climb(n, m);
  return 0;
}