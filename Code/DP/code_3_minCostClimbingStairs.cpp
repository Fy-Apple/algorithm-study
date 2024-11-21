//
// Created by Orange on 2024/11/20.
//
#include "code_0_headers.h"
// 746. 使用最小花费爬楼梯
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int cur = 0, prev = 0;
    for (int  i = 2; i <= cost.size(); ++i) {
      const int next = min(cur + cost[i - 1], prev + cost[i - 2]);
      prev = cur;
      cur = next;
    }
    return cur;
  }
};