//
// Created by Orange on 2024/10/31.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    int max = 0;
    for (int i = 0; i < nums.size(); ++i) {
      dp[i] = 1;
      for (int j = i - 1; j >= 0; --j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
          max = max(max, dp[i]);
        }
      }
    }
    return max;
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1,3,6,7,9,4,10,5,6};
  s.lengthOfLIS(test);
  return 0;
}
