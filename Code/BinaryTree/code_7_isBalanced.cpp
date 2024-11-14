//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"

class Solution {
public:
  int maxDist(TreeNode* root) {
    if (!root) return 0;
    const int left = maxDist(root->left);
    if (left == -1) return -1;
    const int right = maxDist(root->right);
    if (right == -1) return -1;
    return abs(left - right) > 1 ? -1 : max(left, right) + 1;
  }
  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    return maxDist(root) != -1;
  }
};