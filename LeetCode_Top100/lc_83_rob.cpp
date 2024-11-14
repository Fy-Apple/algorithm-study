//
// Created by apple on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  // 优化空间
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int money1 = nums[0], money2 = max(nums[0], nums[1]);
    for (int i = 2; i <nums.size(); ++i) {
      const int curMoney = max(money1 + nums[i], money2);
      money1 = money2;
      money2 = curMoney;
    }
    return max(money1, money2);
  }
  int rob2(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> moneys(nums.size(), 0);
    moneys[0] = nums[0];
    moneys[1] = nums[1];
    moneys[2] = nums[2];
    for (int i = 3; i <nums.size(); ++i) {
      moneys[i] = max(moneys[i - 2], moneys[i - 3]) + nums[i];
    }
    return max(moneys[nums.size() - 1], moneys[nums.size() - 2]);
  }
};