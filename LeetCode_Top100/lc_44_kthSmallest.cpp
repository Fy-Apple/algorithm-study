//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <queue>
#include <stack>
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
  int kthSmallest(TreeNode* root, int k) {
    priority_queue<int> q;
    stack<TreeNode*> tStack;
    TreeNode *cur = root;
    while (cur || !tStack.empty()) {
      while (cur) {
        tStack.push(cur);
        cur = cur->left;
      }
      cur = tStack.top();
      tStack.pop();
      q.push(cur->val);
      if (q.size() > k) q.pop();
      cur = cur->right;
    }
    return q.top();
  }
};