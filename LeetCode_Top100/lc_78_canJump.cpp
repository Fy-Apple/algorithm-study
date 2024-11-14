//
// Created by apple on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums.size() <= 1) return true;
    int maxJump = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (i > maxJump) return false;
      if (nums[i] >= nums[i - 1]) {
        maxJump = max(maxJump, i + nums[i]);
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> test = {2, 3, 1, 1, 4};
  vector<int> test2 = {2, 0, 0};
  cout << s.canJump(test) << ", " << s.canJump(test2);
  return 0;
}