//
// Created by orange on 11/10/24.
//
#include <unordered_map>
#include <vector>
using namespace std;

// 1. 两数之和
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.count(target - nums[i])) return {i, map[target - nums[i]]};
      map.emplace(nums[i], i);
    }
    return {-1, -1};
  }
};

int main(int argc, char* argv[]) {


  return 0;
}