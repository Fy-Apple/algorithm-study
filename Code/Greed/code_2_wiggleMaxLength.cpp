//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

// 376. 摆动序列
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2)
      return nums.size();

    int up = 1, down = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        up = down + 1;
      } else if (nums[i] < nums[i - 1]) {
        down = up + 1;
      }
    }

    return max(up, down);
  }

  int wiggleMaxLength2(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int prediff = 0, curdiff = 0, result = 1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      curdiff = nums[i + 1] - nums[i];
      if ((curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0)) {
        ++result;
        prediff = curdiff;
      }
    }
    return result;
  }
};


int main(int argc, char *argv[]) {
  vector<int> test = {33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
  Solution s;
  cout << s.wiggleMaxLength(test);
}
