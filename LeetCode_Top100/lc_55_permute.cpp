//
// Created by apple on 2024/10/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<bool> tags;
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    tags.resize(nums.size(),false);
    vector<int> cur;
    dfs(nums, result, cur);
    return result;
  }


  void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& cur) {
    for (int i = 0; i < nums.size(); ++i) {
      if (tags[i] == false) {
        tags[i] = true;
        cur.push_back(nums[i]);
        if (cur.size() == nums.size()) {
          result.emplace_back(cur);
        }
        dfs(nums, result, cur);
        tags[i] = false;
        cur.pop_back();
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 2, 3};
  for (const auto& v : s.permute(test)) {
    cout << "[";
    for (const auto& num : v) {
      cout << num << " ";
    }
    cout << "], ";
  }

  return 0;
}
