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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      size_t curSize = que.size() + 1;
      while (--curSize) {
        TreeNode * temp = que.front()->left;
        que.front()->left = que.front()->right;
        que.front()->right = temp;
        if (que.front()->left) que.push(que.front()->left);
        if (que.front()->right) que.push(que.front()->right);
        que.pop();
      }
    }
    return root;
  }
};