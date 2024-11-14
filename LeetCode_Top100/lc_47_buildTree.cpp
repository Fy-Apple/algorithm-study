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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() && inorder.empty()) return nullptr;
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
      inMap[inorder[i]] = i;
    }
    return buildNode(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1, inMap);
  }

  TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2, unordered_map<int, int>& inMap) {
    if (l1 > r1 || l2 > r2) return nullptr;
    int rootValue = preorder[l1];
    int rootIndex = inMap[rootValue];
    int leftNum = rootIndex - l2;
    auto node = new TreeNode(preorder[l1]);
    node->left = buildNode(preorder, inorder, l1 + 1, l1 + leftNum, l2, rootIndex - 1, inMap);
    node->right = buildNode(preorder, inorder, l1 + leftNum + 1, r1, rootIndex + 1, r2, inMap);
    return node;
  }
};