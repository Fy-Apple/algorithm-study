//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <vector>
using namespace std;

//  27.移除元素
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int slow = 0, fast = 0;
    for (; fast < nums.size(); ++fast) {
      if (nums[fast] != val) {
        nums[slow++] =  nums[fast];
      }
    }
    int result = fast;
    for (; fast >= slow; --fast) {
      nums.pop_back();
    }
    return result;
  }
};