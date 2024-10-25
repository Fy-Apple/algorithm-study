//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int maxLen = 0;
    stack<TreeNode*> s;
    unordered_map<TreeNode*, int> depthMap;
    TreeNode *cur = root, *prevNode = nullptr;
    while (!s.empty() || cur) {
      if (cur) {
        s.push(cur);
        cur = cur->left;
      }else {
        TreeNode *node = s.top();
        if (!node->right || prevNode == node->right) {
          // 处理
          int leftDepth = node->left ? depthMap[node->left] : 0;
          int rightDepth = node->right ? depthMap[node->right] : 0;
          maxLen = max(maxLen, leftDepth + rightDepth);
          depthMap[node] = max(leftDepth, rightDepth) + 1;
          s.pop();
          prevNode = node;
        }else {
          cur = node->right;
        }
      }
    }
    return maxLen;
  }
};