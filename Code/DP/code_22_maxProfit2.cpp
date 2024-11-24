//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"

// 122. 买卖股票的最佳时机 II
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<int> dp(prices.size());
    dp[0] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i] = dp[i - 1];
      if (prices[i] > prices[i - 1])
        dp[i] += prices[i] - prices[i - 1];
    }
    return dp[prices.size() - 1];
  }
  int maxProfit2(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0] = {-prices[0], 0};
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
  }
  //优化
  int maxProfit3(vector<int>& prices) {
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1])
        result += prices[i] - prices[i - 1];
    }
    return result;
  }
};