//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"


class Solution {
public:
  // 513. 找树左下角的值
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    if (!root) return -1;
    q.push(root);
    int num = root->val;
    while (!q.empty()) {
      const size_t size = q.size();
      for (size_t i = 0; i < size; ++i) {
        if (i == 0) num = q.front()->val;
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }
    return num;
  }
  // 优化
  int findBottomLeftValue2(TreeNode* root) {
    queue<TreeNode*> q;
    if (!root) return -1;
    q.push(root);
    int num = root->val;
    while (!q.empty()) {
      if (q.front()->right) q.push(q.front()->right);
      if (q.front()->left) q.push(q.front()->left);
      num = q.front()->val;
      q.pop();
    }
    return num;
  }

  // dfs
  void dfs(TreeNode* node, int depth, int& val, int& maxDepth) {
    if (!node) return ;
    maxDepth = max(maxDepth, depth + 1);
    dfs(node->right, depth + 1, val, maxDepth);
    dfs(node->left, depth + 1, val, maxDepth);
    if (depth + 1 >= maxDepth) {
      val = node->val;
      maxDepth = depth + 1;
    }
  }
  int findBottomLeftValue3(TreeNode* root) {
    int result = 0;
    int maxDepth = 0;
    dfs(root, 0, result, maxDepth);
    return result;
  }
};