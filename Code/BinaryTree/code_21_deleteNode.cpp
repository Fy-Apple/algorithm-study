//
// Created by Orange on 2024/11/13.
//
#include "code_0_binarytree.h"
class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    TreeNode *cur = root, *prev = nullptr;
    while (cur && cur->val != key) {
      prev = cur;
      if (key < cur->val) cur = cur->left;
      else cur = cur->right;
    }
    if (!cur) return root;
    if (!cur->left && !cur->right) {
      if (prev) {
        if (prev->left == cur) prev->left = nullptr;
        else prev->right = nullptr;
      }
      delete cur;
      return prev ? root : nullptr;
    }
    if (cur->left && cur->right) {
      prev = cur;
      TreeNode *replace = cur->right;
      while (replace->left) {
        prev = replace;
        replace = replace->left;
      }
      swap(cur->val, replace->val);
      cur = replace;
    }
    if (prev) {
      if (prev->left == cur) prev->left = cur->left ? cur->left : cur->right;
      else prev->right = cur->left ? cur->left : cur->right;
    }else {
      root = cur->left ? cur->left : cur->right;
    }
    delete cur;
    return root;
  }
};