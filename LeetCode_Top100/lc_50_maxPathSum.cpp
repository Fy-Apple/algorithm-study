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
private:
  int maxNum;
public:
  int maxPathSum1(TreeNode* root) {
    if (!root) return 0;
    unordered_map<TreeNode*, int> sumMap;
    stack<TreeNode*> nodeStack;
    int maxPath = INT_MIN;
    TreeNode *cur = root, *prevNode = nullptr;
    while (cur || !nodeStack.empty()) {
      while (cur) {
        nodeStack.push(cur);
        cur = cur->left;
      }
      TreeNode *node = nodeStack.top();
      if (!node->right || node->right == prevNode) {
        int leftSum = node->left ? max(sumMap[node->left], 0) : 0;
        int rightSum = node->right ? max(sumMap[node->right], 0) : 0;

        maxPath = max(maxPath, max(node->val, leftSum + rightSum + node->val));

        sumMap[node] = max(leftSum, rightSum) + node->val;
        nodeStack.pop();
        prevNode = node;
      }else {
        cur = node->right;
      }
    }
    return maxPath;
  }



  int maxPathSum2(TreeNode* root) {
    maxNum = INT_MIN;
    dfs(root);
    return maxNum;
  }

  int dfs(TreeNode* root) {
    if (!root) return 0;

    int left = std::max(dfs(root->left), 0);
    int right = std::max(dfs(root->right), 0);

    int currentMax = root->val + left + right;

    maxNum = std::max(maxNum, currentMax);

    return root->val + std::max(left, right);
  }
};