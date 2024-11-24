//
// Created by Orange on 2024/11/25.
//
#include "code_0_headers.h"

// 84. 柱状图中最大的矩形
class Solution {
public:
  // 单调栈
  int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    heights.emplace_back(0); // 方便计算
    int result = 0;
    for (int i = 0; i < heights.size(); ++i) {
      while (!stk.empty() && heights[i] < heights[stk.top()]) {
        const int h = heights[stk.top()];
        stk.pop();
        const int w = stk.empty() ? i : (i - stk.top() - 1);
        result = max(result, h * w);
      }
      stk.push(i);
    }
    return result;
  }

  // 暴力
  int largestRectangleArea2(vector<int>& heights) {
    stack<int> stk;
    int result = 0;
    // 枚举每一个柱子
    for (int i = 0; i < heights.size(); ++i) {
      int l = i, r = i;
      while (l - 1 >= 0 && heights[l - 1] >= heights[i]) --l;
      while (r + 1 < heights.size() && heights[r +1] >= heights[i]) ++r;
      result = max(result, heights[i] * (r - l + 1));
    }
    return result;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> test = {2, 1, 5, 6, 2, 3};
  cout << s.largestRectangleArea(test);
  return 0;
}
