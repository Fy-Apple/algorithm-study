//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"

// 188. 买卖股票的最佳时机 IV
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    vector<int> buy(k + 1, -prices[0]);
    vector<int> sell(k + 1, 0);
    for (const int& price : prices) {
      //今天股价price
      for (int count = 1; count <= k; ++count) {
        // 第count次买入股票的最大利润为，不算今天的股价，之前的第count次买入的最大利润，或者，第count-1次卖出的利润减去今天的股价买入的钱
        buy[count] = max(buy[count], sell[count - 1] - price);
        // 第count次卖出股票的最大利润为：不算今天的股价，之前的所有股价计算出的第count次卖出的值，或者，第count次买入的值加上今天卖出的值
        sell[count] = max(sell[count], buy[count] + price);
      }
    }
    return sell[k];
  }
};