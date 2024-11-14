//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"

class Solution {
public:
  // 701. 二叉搜索树中的插入操作
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val > val) root->left  = insertIntoBST(root->left, val);
    else  root->right = insertIntoBST(root->right, val);
    return root;
  }

  //
  TreeNode* insertIntoBST2(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    TreeNode *prev = nullptr, *cur = root;
    while (cur) {
      prev = cur;
      if (cur->val > val) {
        cur = cur->left;
      }else {
        cur = cur->right;
      }
    }
    if (prev->val > val) {
      prev->left = new TreeNode(val);
    }else {
      prev->right = new TreeNode(val);
    }
    return root;

  }

};

