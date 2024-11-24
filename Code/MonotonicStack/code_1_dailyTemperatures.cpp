//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 739. 每日温度
class Solution {
public:
  // 跳转
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size());

    for (int i = static_cast<int>(temperatures.size()) - 2; i >= 0; --i) {
      int j = i + 1;
      while (j < static_cast<int>(temperatures.size()) && temperatures[j] <= temperatures[i] && result[j] != 0) {
        j += result[j];
      }
      if (j < static_cast<int>(temperatures.size()) && temperatures[j] > temperatures[i]) {
        result[i] = j - i;
      }
    }
    return result;
  }

  // 单调栈 (寻找某个节点附近第一个具有xxx属性的节点，)
  vector<int> dailyTemperatures2(vector<int>& temperatures) {
    // 单调递减栈，存放下标
    stack<int> stk;
    // 结果数组
    vector<int> result(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); ++i) {
      while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        const int idx = stk.top();
        stk.pop();
        result[idx] = i - idx;
      }
      stk.push(i);
    }
    return result;
  }
};