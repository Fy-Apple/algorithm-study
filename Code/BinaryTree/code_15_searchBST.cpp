//
// Created by orange on 11/12/24.
//
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  // 700. 二叉搜索树中的搜索
  TreeNode* searchBSTDFS(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val > val) return searchBSTDFS(root->left, val);
    if (root->val < val) return searchBSTDFS(root->right, val);
    return root;
  }

  TreeNode* searchBST(TreeNode* root, int val) {
    stack<TreeNode*> stk;
    if (!root) return nullptr;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* cur = stk.top();
      stk.pop();
      if (cur == nullptr) return nullptr;
      if (cur->val == val) return cur;
      if (cur->val > val) stk.push(cur->left);
      else stk.push(cur->right);
    }
    return nullptr;
  }
};