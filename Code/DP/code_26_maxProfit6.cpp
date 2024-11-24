//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"
// 714. 买卖股票的最佳时机含手续费
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return dp.back()[1];
  }

  // 压缩空间
  int maxProfit2(vector<int>& prices, int fee) {
    int buy =  -prices[0];
    int sell = 0;
    for (int i = 1; i < prices.size(); ++i) {
      const int newbuy = max(buy, sell - prices[i]);
      sell = max(sell, buy + prices[i] - fee);
      buy = newbuy;
    }
    return sell;
  }
  // 贪心
  int maxProfit3(vector<int>& prices, int fee) {
    int pf = 0;
    int low = prices[0] + fee;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] + fee < low) {
        low = prices[i] + fee;
      }
      else if (prices[i] > low) {
        pf += prices[i] - low;
        low = prices[i] + fee;
      }
    }
    return pf;
  }
};