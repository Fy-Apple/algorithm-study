//
// Created by Orange on 2024/11/20.
//
#include "../BinaryTree/code_0_binarytree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 *
 */
// 968. 监控二叉树
class Solution {
public:
  int minCameraCover(TreeNode* root) {
    int result = 0;
    if (dfs(root, result) == 0) {
      ++result;
    };
    return result;
  }

  int dfs(TreeNode *node, int& result) {
    if (!node) return 1;
    const int left = dfs(node->left, result);
    const int right = dfs(node->right, result);
    if (left == 0 || right == 0) {
      ++result;
      return 2;
    }
    if (left == 2 || right == 2) {
      return 1;
    }
    return 0;
  }

};