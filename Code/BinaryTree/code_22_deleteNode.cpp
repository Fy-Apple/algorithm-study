//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    TreeNode *cur = root, *prev = nullptr;
    bool isLeft = true;
    while (cur && cur->val != key) {
      prev = cur;
      if (cur->val > key) {
        cur = cur->left;
        isLeft = true;
      }
      else {
        cur = cur->right;
        isLeft = false;
      }
    }
    if (!cur) return root;
    while (true) {
      if (!cur->left && !cur->right) {
        if (prev) {
          if (isLeft) prev->left = nullptr;
          else prev->right = nullptr;
        }
        delete cur;
        break;
      }
      TreeNode *replace;
      if (cur->left) {
        prev = cur;
        isLeft = true;
        replace = cur->left;
        while (replace->right) {
          prev = replace;
          isLeft = false;
          replace = replace->right;
        }
      }else {
        prev = cur;
        isLeft = false;
        replace = cur->right;
        while (replace->left) {
          prev = replace;
          isLeft = true;
          replace = replace->left;
        }
      }
      swap(cur->val, replace->val);
      cur = replace;
    }
    return root;
  }
};