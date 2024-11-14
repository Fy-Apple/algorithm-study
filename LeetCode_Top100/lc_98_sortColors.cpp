//
// Created by orange on 11/5/24.
//
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, i = 0;
    while (i <= right) {
      if (nums[i] < 1) {
        swap(nums[i], nums[left]);
        ++left;
        ++i;
      }else if (nums[i] > 1) {
        swap(nums[i], nums[right]);
        --right;
      }else {
        ++i;
      }
     }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {2, 0, 1};
  s.sortColors(test);
  for (auto n : test) {
    cout << n << ", ";
  }

  return 0;
}

