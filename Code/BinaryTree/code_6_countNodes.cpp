//
// Created by orange on 11/11/24.
//
#include <cmath>
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  // 222. 完全二叉树的节点个数
  int countNodesRec(TreeNode* root) {
    if (!root) return 0;
    return countNodesRec(root->left) + countNodesRec(root->right) + 1;
  }

  int countNodes2(TreeNode* root) {
    int num = 0;
    stack<TreeNode*> nodeStack;
    if (root) nodeStack.push(root);
    while (!nodeStack.empty()) {
      ++num;
      const TreeNode * const cur = nodeStack.top();
      nodeStack.pop();
      if (cur->right) nodeStack.push(cur->right);
      if (cur->left) nodeStack.push(cur->left);
    }
    return num;
  }
  // 性质
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int lDepth = 0, rDepth = 0;
    TreeNode *temp = root;
    while (temp->left) {
      ++lDepth;
      temp = temp->left;
    }
    temp = root;
    while (temp->right) {
      ++rDepth;
      temp = temp->right;
    }
    if (lDepth == rDepth) return pow(2, lDepth + 1) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
