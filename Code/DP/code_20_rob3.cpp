//
// Created by Orange on 2024/11/23.
//
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
#include "../BinaryTree/code_0_binarytree.h"

#include <stack>
#include <unordered_map>
// 337. 打家劫舍 III
class Solution {
public:
  int rob(TreeNode* root) {
    vector<TreeNode*> father;
    const auto pr = dfs(root);
    return max(pr.first, pr.second);
  }

  pair<int, int> dfs(TreeNode *node) {
    if (!node) return {0, 0};
    const auto left = dfs(node->left);
    const auto right = dfs(node->right);
    return {node->val + left.second + right.second, max(max(left.first + right.first, left.second + right.second), max(left.first + right.second, left.second + right.first))};
  }

  int rob2(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode *cur = root, *prev = nullptr;
    unordered_map<TreeNode*, pair<int, int>> mp;
    while (cur || !stk.empty()) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = stk.top();
      if (!node->right || node->right == prev) {
        // 访问当前节点
        const pair<int,int> left = node->left ? mp[node->left] : make_pair(0, 0);
        const pair<int,int> right = node->right ? mp[node->right] : make_pair(0, 0);
        mp[node] = make_pair(node->val + left.second + right.second, max(max(left.first + right.first, left.second + right.second), max(left.first + right.second, left.second + right.first)));
        stk.pop();
        prev = node;
      } else {
        // 优先访问右孩子
        cur = node->right;
      }
    }
    return root ? max(mp[root].first, mp[root].second) : 0;
  }
};