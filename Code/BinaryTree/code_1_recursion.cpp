//
// Created by orange on 11/11/24.
//
#include "code_0_binarytree.h"



class Solution {
public:
  void preorderDfs(TreeNode *node, vector<int>& v) {
    if (node == nullptr) return;
    v.emplace_back(node->val);
    preorderDfs(node->left, v);
    preorderDfs(node->right,v);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorderDfs(root, result);
    return result;
  }


  void inorderDfs(TreeNode *node, vector<int>& v) {
    if (node == nullptr) return;
    inorderDfs(node->left, v);
    v.emplace_back(node->val);
    inorderDfs(node->right,v);
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderDfs(root, result);
    return result;
  }


  void postorder(TreeNode *node, vector<int>& v) {
    if (node == nullptr) return;
    postorder(node->left, v);
    postorder(node->right,v);
    v.emplace_back(node->val);
  }
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorder(root, result);
    return result;
  }
};