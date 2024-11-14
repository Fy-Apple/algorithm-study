//
// Created by orange on 11/11/24.
//
#include "code_0_binarytree.h"


class Solution {
public:
  // 104. 二叉树的最大深度
  int maxDepthRec(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepthRec(root->left), maxDepthRec(root->right)) + 1;
  }

  int maxDepth(TreeNode* root) {
    queue<TreeNode*> q;
    if (root) q.push(root);
    int depth = 0;
    while (!q.empty()) {
      size_t size = q.size();
      ++depth;
      while (size--) {
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }
    return depth;
  }

  // 111. 二叉树的最小深度
  int minDepthRec(TreeNode* root) {
    if (!root) return 0;
    const int left = minDepthRec(root->left);
    const int right = minDepth(root->right);
    if (left == 0 || right == 0) return left + right + 1;
    return min(left, right) + 1;
  }

  int minDepth(TreeNode* root) {
    queue<TreeNode*> q;
    if (!root) return 0;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      ++depth;
      size_t size = q.size();
      for (size_t i = 0; i < size; ++i) {
        if (!q.front()->left && !q.front()->right) return depth;
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }
    return depth;
  }
};