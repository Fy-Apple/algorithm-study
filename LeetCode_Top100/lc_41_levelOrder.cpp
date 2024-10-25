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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> que;
    que.push(root);
    int i = 0;
    while (!que.empty()) {
      size_t qSize = que.size();
      result.emplace_back(0,0);
      for (size_t index = 0; index < qSize; ++index) {
        result[i].emplace_back(que.front()->val);
        if (que.front()->left) que.push(que.front()->left);
        if (que.front()->right) que.push(que.front()->right);
        que.pop();
      }
      ++i;
    }
    return result;
  }
};