//
// Created by orange on 11/12/24.
//
#include <climits>
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  // 530. 二叉搜索树的最小绝对差
  int getMinimumDifference(TreeNode* root) {
    int pre = -1;
    return dfs(root, pre);
  }
  int dfs(TreeNode* root, int& pre) {
    if (!root) return INT_MAX;
    const int left = dfs(root->left, pre);
    int cur = INT_MAX;
    if (pre != -1) {
      cur = root->val - pre;
    }
    pre = root->val;
    const int right = dfs(root->right, pre);
    return min(cur, min(left, right));
  }
  int getMinimumDifference2(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode *cur = root;
    int minNum = INT_MAX;
    int prev;
    bool first = false;
    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      if (first) {
        minNum = min(minNum, abs(node->val - prev));
      }
      prev = node->val;
      first = true;
      if (node->right) cur = node->right;
    }
    return minNum;
  }
};