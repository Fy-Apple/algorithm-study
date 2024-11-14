//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 239. 滑动窗口最大值
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> maxQ;
    for (int i = 0; i < k; ++i) {
      while (!maxQ.empty() && nums[i] >= nums[maxQ.back()]) maxQ.pop_back();
      maxQ.push_back(i);
    }
    result.push_back(nums[maxQ.front()]);
    for (int i = k; i < nums.size(); ++i) {
      if (maxQ.front() == i - k) maxQ.pop_front();
      while (!maxQ.empty() && nums[i] >= nums[maxQ.back()]) maxQ.pop_back();
      maxQ.push_back(i);
      result.push_back(nums[maxQ.front()]);
    }
    return result;
  }
};

int main(int argc, char* argv[]) {


  return 0;
}