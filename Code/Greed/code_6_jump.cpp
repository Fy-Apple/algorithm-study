//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

//45.跳跃游戏 II
class Solution {
public:
  int jump(vector<int>& nums) {
    int maxIndex = 0, curEnd = 0;
    int jump = 0;
    for (int i = 0; i < nums.size(); ++i) {
      maxIndex = max(maxIndex, i + nums[i]);
      if (i == curEnd) {
        ++jump;
        curEnd = maxIndex;
      }
    }
    return jump;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {2, 3, 1};
  cout << s.jump(test);
  return 0;
}
