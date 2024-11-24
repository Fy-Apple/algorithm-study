//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 300. 最长递增子序列
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int maxlen = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if(nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1,3,6,7,9,4,10,5,6};
  cout << s.lengthOfLIS(test);
  return 0;
}
