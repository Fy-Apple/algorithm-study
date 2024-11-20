//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

//122.买卖股票的最佳时机 II
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) {
        result += prices[i] - prices[i - 1];
      }
    }
    return result;
  }
};