//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <queue>
using namespace std;


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
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> que;
    que.push(root);
    int depth = 0;
    TreeNode* cur;
    while (!que.empty()) {
      ++depth;
      size_t curSize = que.size();
      for (size_t i = 0; i < curSize; ++i) {
        cur = que.front();
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
        que.pop();
      }
    }
    return depth;
  }
};