//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"
//518. 零钱兑换 II

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= coins.size(); ++i) dp[i][0] = 1;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = 1; j <= amount; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
      }
    }
    return dp[coins.size()][amount];
  }

  int change2(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = coins[i - 1]; j <= amount; ++j) {
        if (dp[j] < INT_MAX - dp[j - coins[i]])
          dp[j] += dp[j - coins[i - 1]];
      }
    }
    return dp[amount];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 2, 5};
  cout << s.change2(5, test);
  return 0;
}


