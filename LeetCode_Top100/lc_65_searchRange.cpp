//
// Created by apple on 2024/10/28.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        left = mid;
        right = mid;
        while (left - 1 >= 0 && nums[left - 1] == target) --left;
        while (right + 1 < nums.size() && nums[right + 1] == target ) ++right;
        return {left, right};
      }
      if (nums[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    return {-1, -1};
  }
  vector<int> searchRange2(vector<int>& nums, int target) {
    int first, last;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        first = mid;
        right = mid - 1;
      }else if (nums[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        last = mid;
        left = mid + 1;
      }else if (nums[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    return {first, last};
  }
};


int main(int argc, char *argv[]) {


  return 0;
}

