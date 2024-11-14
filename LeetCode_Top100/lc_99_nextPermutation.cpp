//
// Created by orange on 11/5/24.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >=0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
      int j = nums.size() - 1;
      while (nums[i] >= nums[j]) --j;
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 2, 3};
  s.nextPermutation(test);
  return 0;
}
