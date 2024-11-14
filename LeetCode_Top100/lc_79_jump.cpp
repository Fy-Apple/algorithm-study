//
// Created by apple on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int jump(vector<int>& nums) {
    // if (nums.size() <= 1)
    //     return 0;
    // int curIndex = 0;
    // int jumpNum = 0;
    // while (true) {
    //     ++jumpNum;
    //     if (curIndex + nums[curIndex] >= nums.size() - 1)
    //         return jumpNum;
    //     int curJumpNum = curIndex + nums[curIndex];
    //     int curNum = nums[curIndex];
    //     int nextIndex = curIndex;
    //     while (curNum--) {
    //         ++curIndex;
    //         if (curIndex + nums[curIndex] >= curJumpNum) {
    //             curJumpNum = curIndex + nums[curIndex];
    //             nextIndex = curIndex;
    //         }
    //     }
    //     curIndex = nextIndex;
    // }
    int jumps = 0, curEnd = 0, farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
      farthest = max(farthest, i + nums[i]);
      if (i == curEnd) {
        ++jumps;
        curEnd = farthest;
      }
    }

    return jumps;
  }
};
int main() {
  Solution s;
  vector<int> test = {2,3,1,1,4};
  vector<int> test2 = {3, 2, 1};
  cout << s.jump(test) << ", " << s.jump(test2);
  return 0;
}