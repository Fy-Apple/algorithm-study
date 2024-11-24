//
// Created by Orange on 2024/11/25.
//
#include "code_0_headers.h"

// 42. 接雨水
class Solution {
public:
  // 单调栈
  int trap(vector<int>& height) {
    stack<int> stk;
    int result = 0;
    for (int i = 0; i < height.size(); ++i) {
      while (!stk.empty() && height[i] > height[stk.top()]) {
        int h = stk.top();
        stk.pop();
        if (stk.empty()) break;
        const int w = i - stk.top() - 1;
        h = min(height[i], height[stk.top()]) - height[h];
        result += w * h;
      }
      stk.push(i);
    }
    return result;
  }

  // 动态规划
  int trap2(vector<int>& height) {
    const int size = static_cast<int>(height.size());
    if (size <= 2) return 0;
    vector<int> left(size), right(size);
    left[0] = height[0];
    for (int i = 1; i < size; ++i) {
      left[i] = max(left[i - 1], height[i]);
    }
    right[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; --i) {
      right[i] = max(right[i + 1], height[i]);
    }
    int result = 0;
    for (int i = 0; i < size; ++i) {
      result += min(left[i], right[i]) - height[i];
    }
    return result;
  }

  // 双指针
  int trap3(vector<int>& height) {
    int l = 0, r = static_cast<int>(height.size()) - 1;
    int left = 0, right = 0;
    int result = 0;

    while (l < r) {
      left = max(left, height[l]);
      right = max(right, height[r]);
      if (height[l] < height[r]) {
        result += left - height[l++];
      }else {
        result += right - height[r--];
      }
    }
    return result;
  }

  // 暴力解法，按列
  int trap4(vector<int>& height) {
    int result = 0;

    for (int i = 1; i < static_cast<int>(height.size()) - 1; ++i) {
      int l = height[i - 1], r = height[i + 1];
      for (int left = i - 2; left >= 0; --left) {
        l = max(l, height[left]);
      }
      for (int right = i + 2; right < height.size(); ++right) {
        r = max(r, height[right]);
      }

      if (l> height[i] && r > height[i]) {
        result += min(l, r) - height[i];
      }
    }
    return result;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << s.trap4(test);
  return 0;
}
