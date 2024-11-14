//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"

class Solution {
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return nullptr;
    if (root1 && !root2) return root1;
    if (!root1) return root2;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
  }
};