//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <queue>
#include <stack>
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
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    stack<TreeNode*> sT;

    TreeNode *lastNode = nullptr;
    TreeNode *cur = root;
    while (cur || !sT.empty()) {
      while (cur) {
        sT.push(cur);
        cur = cur->left;
      }

      cur = sT.top();
      if (lastNode && cur->val <= lastNode->val) return false;
      lastNode = cur;
      sT.pop();
      cur = cur->right;
    }
    return true;
  }
};