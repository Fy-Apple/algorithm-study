//
// Created by orange on 11/12/24.
//
#include "code_0_binarytree.h"

class Solution {
public:
  void dfs(TreeNode *node, vector<string>& result, vector<int>& cur) {
    if (!node) return;
    if (!node->left && !node->right) {
      cur.push_back(node->val);
      string s;
      for (int i = 0; i < cur.size(); ++i) {
        s.append(to_string(cur[i]));
        if (i != cur.size() - 1) s.append("->");
      }
      result.emplace_back(s);
      cur.pop_back();
      return;
    }
    cur.push_back(node->val);
    dfs(node->left, result, cur);
    cur.pop_back();
    cur.push_back(node->val);
    dfs(node->right, result, cur);
    cur.pop_back();
  }
  vector<string> binaryTreePaths2(TreeNode* root) {
    vector<string> result;
    if (!root) return result;
    vector<int> cur;
    dfs(root, result, cur);
    return result;
  }

  void dfs2(TreeNode *node, vector<string>& result, string path) {
    if (!node->left && !node->right) {
      result.push_back(path + "->" + to_string(node->val));
    }
    if (node->left) dfs2(node->left, result, path + "->" + to_string(node->val));
    if (node->right) dfs2(node->right, result, path + "->" + to_string(node->val));
  }
  // 优化
  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return {};
    vector<string> result;
    dfs2(root, result, "");
    return result;
  }


};

