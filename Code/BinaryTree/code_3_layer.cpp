//
// Created by orange on 11/11/24.
//
#include "code_0_binarytree.h"


class Solution {
public:
  // 102 层序遍历
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      const size_t size = q.size();
      vector<int> cur;
      for (size_t i = 0; i < size; ++i) {
        const TreeNode* const node = q.front();
        cur.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
      }
      result.push_back(cur);
    }
    return result;
  }
  // 107 层序遍历II
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      const size_t size = q.size();
      vector<int> cur;
      for (size_t i = 0; i < size; ++i) {
        const TreeNode* const node = q.front();
        cur.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
      }
      result.push_back(cur);
    }
    reverse(result.begin(),result.end());
    return result;
  }
  // 199 二叉树的右视图
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty()) {
      size_t size = q.size();
      while (--size) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
      result.emplace_back(q.front()->val);
      if (q.front()->left) q.emplace(q.front()->left);
      if (q.front()->right) q.emplace(q.front()->right);
      q.pop();
    }
    return result;
  }

  // 637. 二叉树的层平均值
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty()) {
      const size_t size = q.size();
      double sum = 0;
      for (size_t i = 0; i < size; ++i) {
        const TreeNode *const node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        sum += node->val;
      }
      result.push_back(sum / static_cast<int>(size));
    }
    return result;
  }

  // 515. 在每个树行中找最大值
  vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty()) {
      const size_t size = q.size();
      int maxNum = q.front()->val;
      for (size_t i = 0; i < size; ++i) {
        const TreeNode *const node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        maxNum = max(maxNum, node->val);
      }
      result.push_back(maxNum);
    }
    return result;
  }

  // 116. 填充每个节点的下一个右侧节点指针
  Node* connect(Node* root) {
    vector<int> result;
    queue<Node*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty()) {
      const size_t size = q.size();
      for (size_t i = 0; i < size; ++i) {
        Node *const node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (i != size - 1) {
          node->next = q.front();
        }else {
          node->next = nullptr;
        }
      }
    }
    return root;
  }

  // 117. 填充每个节点的下一个右侧节点指针 II
  Node* connect2(Node* root) {
    vector<int> result;
    queue<Node*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty()) {
      const size_t size = q.size();
      for (size_t i = 0; i < size; ++i) {
        Node *const node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (i != size - 1) {
          node->next = q.front();
        }else {
          node->next = nullptr;
        }
      }
    }
    return root;
  }

  // 104. 二叉树的最大深度
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
  int maxDepth2(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    int depth = 0;
    while (!q.empty()) {
      const size_t size = q.size();
      ++depth;
      for (size_t i = 0; i < size; ++i) {
        TreeNode *const node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return depth;
  }

  // 111. 二叉树的最小深度
  int minDepth(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    int depth = 0;
    while (!q.empty()) {
      const size_t size = q.size();
      ++depth;
      for (size_t i = 0; i < size; ++i) {
        TreeNode *const node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (!node->left && !node->right) return depth;
      }
    }
    return depth;
  }


};
