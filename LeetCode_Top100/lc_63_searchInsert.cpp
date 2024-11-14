//
// Created by apple on 2024/10/28.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    return left;
  }
};


int main(int argc, char *argv[]) {



  return 0;
}
