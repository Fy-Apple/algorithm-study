//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"

//121. 买卖股票的最佳时机
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int mpf = 0;
    int low = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      mpf = max(mpf, prices[i] - low);
      low = min(low, prices[i]);
    }
    return mpf;
  }

  int maxProfit2(vector<int>& prices) {
    vector<pair<int, int>> dp(prices.size());
    dp[0].first = -prices[0];
    dp[0].second = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i].first = max(dp[i - 1].first,  - prices[i]);
      dp[i].second = max(dp[i - 1].second, dp[i - 1].first + prices[i]);
    }
    return dp.back().second;
  }
};