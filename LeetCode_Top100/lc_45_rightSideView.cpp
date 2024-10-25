#include <queue>
#include <vector>
//
// Created by apple on 2024/10/25.
//
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
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      size_t qSize = que.size();
      while (--qSize) {
        if (que.front()->left) que.push(que.front()->left);
        if (que.front()->right) que.push(que.front()->right);
        que.pop();
      }
      result.emplace_back(que.front()->val);
      if (que.front()->left) que.push(que.front()->left);
      if (que.front()->right) que.push(que.front()->right);
      que.pop();
    }
    return result;
  }
};