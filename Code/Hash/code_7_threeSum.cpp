//
// Created by orange on 11/10/24.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        const int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          result.push_back({nums[i], nums[l], nums[r]});
          while ( l < r && nums[l] == nums[l + 1]) ++l;
          while ( l < r && nums[r] == nums[r - 1]) --l;
          ++l;
          --r;
        }else if (sum > 0) ++l;
        else --r;
      }
    }
    return result;
  }
};


int main(int argc, char* argv[]) {


  return 0;
}


