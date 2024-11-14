//
// Created by orange on 11/11/24.
//
#include "code_0_binarytree.h"


class Solution {
public:
  bool check(TreeNode* left, TreeNode* right) {
    queue<TreeNode*> q;
    q.push(left);
    q.push(right);
    while (!q.empty()) {
      TreeNode *node1 = q.front();
      q.pop();
      TreeNode *node2 = q.front();
      q.pop();
      if (!node1 && !node2) continue;
      if (!node1 || !node2 || node1->val != node2->val) return false;
      q.push(node1->left);
      q.push(node2->right);
      q.push(node1->right);
      q.push(node2->left);
    }
    return true;
  }
  bool isSymmetric(TreeNode* root) {
    return check(root, root);
  }


  bool dfs(TreeNode *left, TreeNode *right) {
    if (left && right && left->val == right->val) return dfs(left->left, right->right) && dfs(left->right, right->left);
    if (!left && !right) return true;
    return false;
  }
  bool isSymmetric2(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return true;
    return dfs(root->left, root->right);
  }
};