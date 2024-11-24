//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

#include <numeric>
// 1049. 最后一块石头的重量 II
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    if (stones.size() == 1) return stones.front();
    const int sum = accumulate(stones.begin(), stones.end(), 0);
    vector<int> dp(sum / 2, 0);
    for (const auto& num : stones) {
      for (int j = sum / 2; j >= num; --j) {
        dp[j] = max(dp[j], dp[j - num] + num);
      }
    }
    return sum - 2 * dp[sum / 2];
  }
};