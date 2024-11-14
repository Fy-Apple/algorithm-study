//
// Created by orange on 11/11/24.
//
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 18. 四数之和
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i] == nums[i] - 1) continue;
      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int l = j + 1, r = nums.size() - 1;
        while (l < r) {
          const int sum = nums[i] + nums[j] + nums[l] + nums[r];
          if (sum == target) {
            result.push_back({nums[i], nums[j], nums[l], nums[r]});
            while(l < r && nums[l] == nums[l + 1]) ++l;
            while(l < r && nums[r] == nums[r - 1]) --r;
            ++l;
            --r;
          }else if (sum > target) {
            --r;
          }else {
            ++l;
          }
        }
      }
    }
    return result;
  }
};


int main(int argc, char* argv[]) {


  return 0;
}