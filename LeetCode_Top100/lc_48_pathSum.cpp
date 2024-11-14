//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <ostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> prefix;
    prefix[0] = 1;
    return dfs(prefix, root, 0, targetSum);
  }
  int dfs(unordered_map<long long, int>& prefix, TreeNode* root, long long cur, int targetSum) {
    if (!root) return 0;
    int ans = 0;
    cur += root->val;
    if (prefix.count(cur - targetSum)) {
      ans = prefix[cur - targetSum];
    }
    ++prefix[cur];
    ans += dfs(prefix, root->left, cur, targetSum);
    ans += dfs(prefix, root->right, cur, targetSum);
    --prefix[cur];
    return ans;
  }
};