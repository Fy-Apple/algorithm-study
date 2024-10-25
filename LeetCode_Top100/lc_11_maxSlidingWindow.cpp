//
// Created by apple on 2024/10/18.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  // 大根堆
  vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<pair<int, int>> pque;
    for (int i = 0; i < k && i < nums.size(); ++i) {
      pque.emplace(nums[i], i);
    }
    result.emplace_back(pque.top().first);
    for (int i = k; i < nums.size(); ++i) {
      pque.emplace(nums[i], i);
      while(pque.top().second < i - k + 1) pque.pop();
      result.emplace_back(pque.top().first);
    }
    return result;
  }

  // 单调队列
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dque;
    for (int i = 0; i < k; ++i) {
      while (!dque.empty() && nums[i] >= nums[dque.back()]) dque.pop_back();
      dque.push_back(i);
    }
    result.emplace_back(nums[dque.front()]);
    for (int i = k; i < nums.size(); ++i) {
      while (!dque.empty() && nums[i] >= nums[dque.back()]) dque.pop_back();
      dque.push_back(i);
      while (!dque.empty() && dque.front() <= i - k) dque.pop_front();
      result.emplace_back(nums[dque.front()]);
    }
    return result;
  }
};


int main(int argc, char** argv) {
  Solution s;
  vector<int> test = {1,3,-1,-3,5,3,6,7};
  for (const auto& num : s.maxSlidingWindow(test, 3)) {
    cout << num << ", ";
  }


  return 0;
}