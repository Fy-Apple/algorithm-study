//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <ostream>
#include <queue>
#include <stack>
#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    std::stack<TreeNode*> tStack;
    tStack.push(root);
    TreeNode *cur = nullptr, *prev = nullptr;
    while (!tStack.empty()) {
      cur = tStack.top();
      tStack.pop();
      if (cur->right) tStack.push(cur->right);
      if (cur->left) tStack.push(cur->left);
      if (!prev) {
        root = cur;
      }else {
        prev->left = nullptr;
        prev->right = cur;
      }
      prev = cur;
    }
  }
};