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
  bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
      const TreeNode* l = q.front(); q.pop();
      const TreeNode* r = q.front(); q.pop();
      if (!l && !r) continue;
      if ((!l || !r) || (l->val != r->val)) return false;
      q.push(l->left);q.push(r->right);
      q.push(l->right);q.push(r->left);
    }
    return true;
  }
};