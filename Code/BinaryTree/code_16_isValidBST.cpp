//
// Created by orange on 11/12/24.
//
#include <limits.h>
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode *cur = root;
    long prev = LONG_MIN;
    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      if (node->val <= prev) return false;
      prev = node->val;
      if (node->right) cur = node->right;
    }
    return true;
  }
};