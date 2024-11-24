//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"
// 309. 买卖股票的最佳时机含冷冻期
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<int> buy(prices.size(), -prices[0]), sell(prices.size(), 0), free(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++i) {
      buy[i] = max(buy[i - 1], free[i - 1] - prices[i]);
      sell[i] = buy[i - 1] + prices[i];
      free[i] = max(sell[i - 1], free[i - 1]);
    }
    return max(sell.back(), free.back());
  }

  // 空间压缩
  int maxProfit2(vector<int>& prices) {
    int buy = -prices[0], sell = 0, free = 0;
    for (int i = 1; i < prices.size(); ++i) {
      // 因为不需要关注 交易次数了，交易次数无限，所以没有不需要内层循环去遍历交易次数了
      const int newbuy = max(buy, free - prices[i]);
      const int newsell = buy + prices[i];
      free = max(sell, free);
      buy = newbuy;
      sell = newsell;
    }
    return max(sell, free);
  }
};

/**
 *    index : [0  1  2  3  4]
 *    value : [1  2  3  0  2]
 *    buy   :
 *
 *    sell  :
 *
 */