//
// Created by orange on 11/12/24.
//
#include <stack>

#include "code_0_binarytree.h"
class Solution {
public:
  // 404. 左叶子之和
  int caculateSum(TreeNode* root, bool isLeft) {
    if (!root->left && !root->right) {
      if (isLeft) return root->val;
      return 0;
    }
    const int left = root->left ? caculateSum(root->left, true) : 0;
    const int right = root->right ? caculateSum(root->right, false) : 0;
    return left + right;
  }
  int sumOfLeftLeaves2(TreeNode* root) {
    if (!root) return 0;
    return caculateSum(root, false);
  }


  int sumOfLeftLeaves(TreeNode* root) {
    stack<TreeNode*> tS;
    if (root) tS.push(root);
    int sum = 0;
    while (!tS.empty()) {
      TreeNode *cur = tS.top();
      tS.pop();
      if (cur->right) {
        tS.push(cur->right);
      }
      if (cur->left) {
        if (!cur->left->left && !cur->left->right) sum += cur->left->val;
        tS.push(cur->left);
      }
    }
    return sum;
  }

};