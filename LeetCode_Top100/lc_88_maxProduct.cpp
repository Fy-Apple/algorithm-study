//
// Created by Orange on 2024/10/31.
//
#include <vector>
using namespace std;
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<pair<int, int>> dp(nums.size() + 1, {1, 1});

    int maxNum = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        dp[i + 1].first = max(dp[i].first * nums[i], nums[i]);
        dp[i + 1].second = min(dp[i].second * nums[i], nums[i]);
      } else if (nums[i] < 0) {
        dp[i + 1].first = max(dp[i].second * nums[i], nums[i]);
        dp[i + 1].second = min(dp[i].first * nums[i], nums[i]);
      } else {
        dp[i + 1] = {1, 1}; // 如果遇到0，重置状态
      }
      maxNum = max(maxNum, dp[i + 1].first);
    }
    return maxNum;
  }
};

int main(int argc, char *argv[]) {

  return 0;

}
