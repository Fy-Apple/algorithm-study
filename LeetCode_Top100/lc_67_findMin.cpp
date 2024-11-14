//
// Created by apple on 2024/10/28.
//
#include <iostream>
#include <vector>
using namespace std;
// [4,5,6,7,1,2,3]
// target :  nums[index] < nums[index - 1]
class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if ((mid == 0 && nums[mid] < nums[nums.size() - 1]) || (mid >= 1 && nums[mid] < nums[mid - 1])) return nums[mid];
      if (nums[left] < nums[right]) return nums[left];
      if (nums[left] < nums[mid]) left = mid + 1;
      else right = mid;
    }
    return left;
  }
};


int main (int agrc, char* argv[]) {


  return 0;
}