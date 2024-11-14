//
// Created by orange on 11/11/24.
//
#include "code_0_binarytree.h"


class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty()) {
      const size_t size = q.empty();
      for (size_t i = 0; i < size; ++i) {
        swap(q.front()->left, q.front()->right);
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }
    return root;
  }
};