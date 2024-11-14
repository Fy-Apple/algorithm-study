//
// Created by apple on 2024/10/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.empty() || target <= 1) return result;
    vector<int> cur;
    dfs(candidates, 0, target, result, cur);
    return result;
  }

  void dfs(vector<int>& candidates, const int index, const int curTarget, vector<vector<int>>& result, vector<int>& cur) {
    if (index == candidates.size()) return;
    if (curTarget == 0) result.emplace_back(cur) ;
    if (curTarget <= 0) return;
    cur.emplace_back(candidates[index]);
    dfs(candidates, index, curTarget - candidates[index], result, cur);
    cur.pop_back();
    dfs(candidates, index + 1, curTarget, result, cur);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {2,3,6,7};
  for (const auto& v : s.combinationSum(test, 7)) {
    cout << "[";
    for (const auto& num : v) {
      cout << num << " ";
    }
    cout << "], " << endl;
  }

  return 0;
}
