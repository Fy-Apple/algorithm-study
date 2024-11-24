
//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

// 卡吗57
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, amount + 1));
    for (int i = 0; i <= coins.size(); ++i) dp[i][0] = 0;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = 1; j <= amount; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= coins[i - 1]) dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
      }
    }
    return dp[coins.size()][amount] == amount + 1 ? -1 : dp[coins.size()][amount];
  }

  int coinChange2(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = coins[i - 1]; j <= amount; ++j) {
        dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 2, 5};
  cout << s.coinChange(test, 11);
  return 0;
}
