//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"


class Solution {
public:
  // 112. 路径总和,dfs
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) {
      if (root->val == targetSum) return true;
      return false;
    }
    bool tag = false;
    if (root->left) tag |= hasPathSum(root->left, targetSum - root->val);
    if (root->right) tag |= hasPathSum(root->right, targetSum - root->val);
    return tag;
  }

  // bfs
  bool hasPathSum2(TreeNode* root, int targetSum) {
    queue<TreeNode*> q;
    queue<int> valQ;
    if (root) {
      q.push(root);
      valQ.push(root->val);
    }
    while (!q.empty()) {
      TreeNode* cur = q.front();
      q.pop();
      const int curVal = valQ.front();
      valQ.pop();
      if (!cur->left && !cur->right) {
        if (curVal == targetSum) return true;
        continue;
      }
      if (cur->left) {
        q.push(cur->left);
        valQ.push(curVal + cur->left->val);
      }
      if (cur->right) {
        q.push(cur->right);
        valQ.push(curVal + cur->right->val);
      }
    }
    return false;
  }
};