//
// Created by apple on 2024/10/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          result.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) ++l;
          while (l < r && nums[r] == nums[r - 1]) --r;
          ++l;
          --r;
        }
        else if (sum < 0) ++l;
        else --r;
      }
    }
    return result;
  }
};

int main(int agrc, char** argv) {
  Solution s;
  vector<int> test = {-1,0,1,2,-1,-4};
  cout << "[";
  for (const auto &v: s.threeSum(test)) {
    cout << "[";
    for (const auto &num: v) {
      cout << num << ",";
    }
    cout << "]";
  }
  cout << "]";
  return 0;
}