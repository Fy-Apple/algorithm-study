//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

// 134. 加油站
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    const int n = static_cast<int>(gas.size());
    bool tag = false;
    for (int i = 0; i < n ; ++i) {
      int size = n;
      int cur = gas[i] - cost[i];
      while (size && cur >= 0) {
        i = (i + 1) % n;
        if (i == 0) tag = true;
        cur = cur + gas[i] - cost[i];
        --size;
      }
      if (size == 0) return i;
      if (i >= 0 && tag) return -1;
    }
    return -1;
  }
  // 优化
  int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      curSum += gas[i] - cost[i];
      totalSum += gas[i] - cost[i];
      if (curSum < 0) {
        curSum = 0;
        start = i + 1;
      }
    }
    return totalSum >= 0 ? start : -1;
  }
};