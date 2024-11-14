//
// Created by orange on 11/11/24.
//
#include <stack>

#include "code_0_binarytree.h"


class Solution {
public:

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodeStack;
    if (root) nodeStack.push(root);
    while (!nodeStack.empty()) {
      TreeNode *cur = nodeStack.top();
      nodeStack.pop();
      if (cur->right) nodeStack.push(cur->right);
      result.push_back(cur->val);
      if (cur->left) nodeStack.push(cur->left);
    }
    return result;
  }


  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodeStack;
    TreeNode *cur = root;
    while (!nodeStack.empty() || cur) {
      while (cur) {
        nodeStack.push(cur);
        cur = cur->left;
      }
      TreeNode *node = nodeStack.top();
      result.push_back(node->val);
      nodeStack.pop();
      if (node->right) cur = node->right;
    }
    return result;
  }


  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodeStack;
    TreeNode *cur = root, *visitedNode = nullptr;
    while (!nodeStack.empty() || cur) {
      while (cur) {
        nodeStack.push(cur);
        cur = cur->left;
      }
      TreeNode *node = nodeStack.top();
      if (!node->right || node->right == visitedNode) {
        nodeStack.pop();
        result.push_back(node->val);
        visitedNode = node;
      }else {
        cur = node->right;
      }
    }
    return result;
  }
};




