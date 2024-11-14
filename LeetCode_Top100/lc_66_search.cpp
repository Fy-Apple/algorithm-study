//
// Created by apple on 2024/10/28.
//
#include <iostream>
#include <vector>
using namespace std;


//left + (right - left) / 2
// 二分小知识 ↑ 防溢出
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    if (nums.empty()) return -1;
    if (nums.size() == 1 && nums[0] > nums[nums.size() - 1]) {
      cout << "here";
      while (left <= right) {
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > nums[left]) {
          if (target > nums[left] && target < nums[mid]) {
            right = mid - 1;
            // 二分
            break;
          }
          left = mid + 1;
        }else {
          if (target < nums[right] && target > nums[mid]) {
            left = mid + 1;
            //二分
            break;
          }
          right = mid - 1;
        }
      }
    }
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {4,5,6,7,0,1,2};
  vector<int> test2 = {1};
  cout << s.search(test2, 0);

  return 0;
}
