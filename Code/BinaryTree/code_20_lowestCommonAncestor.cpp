//
// Created by orange on 11/12/24.
//
#include  "code_0_binarytree.h"

class Solution {
public:
  // 235. 二叉搜索树的最近公共祖先
  TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    int minNum, maxNum;
    if (p->val > q->val) {
      minNum = q->val;
      maxNum = p->val;
    }else {
      minNum = p->val;
      maxNum = q->val;
    }
    TreeNode *left = nullptr, *right = nullptr;
    if (root->val > maxNum) {
      right = lowestCommonAncestor(root->right, p, q);
    }else if (root->val < minNum){
      left = lowestCommonAncestor(root->left, p, q);
    }else {
      return root;
    }
    if (left && right) return root;
    return left ? left : right;
  }
  // 优化
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *cur = root;
    while (true) {
      if (cur->val > p->val && cur->val > q->val) cur = cur->left;
      else if (cur->val < p->val && cur->val < q->val) cur = cur->right;
      else break;
    }
    return cur;
  }
};