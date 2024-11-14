//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    const int len = static_cast<int>(nums.size());
    for (int i = 0; i < len - 3; ++i) {
      if (static_cast<long>(nums[i]) + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;
      if (static_cast<long>(nums[i]) + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < len - 2; ++j) {
        if (static_cast<long>(nums[i]) + nums[j] + nums[len - 1] + nums[len - 2] < target) continue;
        if (static_cast<long>(nums[i]) + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int l = j + 1, r = len - 1;
        while (l < r) {
          const long sum = static_cast<long>(nums[i]) + nums[j] + nums[l] + nums[r];
          if (sum > target) {
            --r;
          }else if (sum < target) {
            ++l;
          }else {
            result.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) ++l;
            while (l < r && nums[r] == nums[r - 1]) --r;
            ++l;
            --r;
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> test = {2, 2, 2, 2, 2};
  for (auto v : s.fourSum(test, 8)) {
    for (auto n : v) {
      cout << n << ", ";
    }
  }

  return 0;
}