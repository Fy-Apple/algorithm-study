//
// Created by apple on 2024/10/26.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    for (int i = 0; i <= nums.size(); ++i) {
      dfs(result, cur, nums, 0, i);
    }
    return result;
  }

  void dfs (vector<vector<int>>& result,  vector<int>& cur, vector<int>& nums, int start, const int num) {
    if (cur.size() == num) {
      result.push_back(cur);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      dfs(result, cur, nums, i + 1, num);
      cur.pop_back();
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 2, 3};
  for (const auto& v : s.subsets(test)) {
    cout << "[";
    for (const auto& num : v) {
      cout << num << " ";
    }
    cout << "], ";
  }
  return 0;
}
