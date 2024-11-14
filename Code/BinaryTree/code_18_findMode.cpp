//
// Created by orange on 11/12/24.
//
#include <limits.h>
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    vector<int> result;
    int num;
    int count;
    int maxCount;
    bool first = true;
    stack<TreeNode*> stk;
    TreeNode *cur = root;
    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      if (first) {
        first = false;
        num = node->val;
        count = 1;
        maxCount = 1;
      }
      else if (num == node->val) {
        ++count;
      }
      else {
        count = 1;
        num = node->val;
      }
      if (count == maxCount) {
        result.push_back(num);
      }
      if (count > maxCount) {
        maxCount = count;
        result = {num};
      }
      if (node->right) cur = node->right;
    }
    return result;
  }
};