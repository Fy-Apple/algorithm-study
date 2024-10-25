//
// Created by apple on 2024/10/19.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    // 考虑以每个元素为结尾的最大子数组和
    // 定义maxPrev[i] 为以i结尾的最大子数组和
    // maxPrev[0] = nums[0]
    // maxPrev[i] = max(maxPrev[i-1] , maxPrev[i-1] + nums[i]);
    vector<int> maxPrev(nums.size());
    if (nums.empty()) return 0;
    maxPrev[0] = nums[0];
    if (nums.size() == 1) return nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      maxPrev[i] = max(nums[i], maxPrev[i - 1] + nums[i]);
    }
    int maxNum = maxPrev[0];
    for (const auto& num : maxPrev) {
      if (maxNum < num) maxNum = num;
    }
    return maxNum;
  }
};


int main(int argc, char** argv) {
  Solution s;
  vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(test);


  return 0;
}