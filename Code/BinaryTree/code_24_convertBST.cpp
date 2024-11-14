//
// Created by Orange on 2024/11/13.
//
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  int dfs(TreeNode *node, const int sum) {
    if (!node) return sum;
    node->val += dfs(node->right, sum);
    return dfs(node->left, node->val);
  }
  TreeNode* convertBST2(TreeNode* root) {
    dfs(root, 0);
    return root;
  }
  TreeNode* convertBST(TreeNode* root) {
    if (!root) return nullptr;
    stack<TreeNode*> stk;
    stack<TreeNode*> invert;
    TreeNode *cur = root;
    while (cur || !stk.empty()) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      invert.push(node);
      if (node->right) cur = node->right;
    }
    int prev = 0;
    while (!invert.empty()) {
      invert.top()->val += prev;
      prev = invert.top()->val;
      invert.pop();
    }
    return root;
  }
};