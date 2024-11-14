//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <ostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    unordered_map<long long, TreeNode*> keyMap;
    unordered_map<TreeNode*, long long> valueMap;
    TreeNode *left = nullptr, *right = nullptr;
    stack<TreeNode*> treeStack;
    treeStack.push(root);
    keyMap[1] = root;
    valueMap[root] = 1;
    while (!treeStack.empty()) {
      TreeNode *node = treeStack.top();
      treeStack.pop();
      long long index = valueMap[node];
      if (node->left) {
        valueMap[node->left] = index * 2;
        keyMap[index * 2] = node->left;
        treeStack.push(node->left);
      }
      if (node->right) {
        valueMap[node->right] = index * 2 + 1;
        keyMap[index * 2 + 1] = node->right;
        treeStack.push(node->right);
      }
      if (node == p) left = node;
      if (node == q) right = node;
      if (left && right) break;
    }
    long long i = valueMap[p];
    long long j = valueMap[q];
    while (i != j) {
      if (i > j) i = i / 2;
      else j = j / 2;
    }
    return keyMap[i];
  }
};

class Solution2 {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
      return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
      return root;

    return left ? left : right;
  }
};