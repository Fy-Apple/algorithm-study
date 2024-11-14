//
// Created by orange on 11/10/24.
//

#include <iostream>
#include <vector>
using namespace std;
// 977.有序数组的平方
class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int size = nums.size();
    vector<int> result(size);
    for (int left = 0, right = size - 1; left <= right; ) {
      if (nums[left] * nums[left] > nums[right] * nums[right]) {
        result[--size] = nums[left] * nums[left];
        ++left;
      }else {
        result[--size] = nums[right] * nums[right];
        --right;
      }
    }
    return result;
  }
};