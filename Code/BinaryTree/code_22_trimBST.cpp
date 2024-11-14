//
// Created by Orange on 2024/11/13.
//
#include <queue>
#include <stack>

#include "code_0_binarytree.h"

class Solution {
public:
  //669. 修剪二叉搜索树, dfs
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }

  // 模拟
  TreeNode* trimBST2(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    queue<TreeNode*> que;
    TreeNode *newRoot = root;
    while (newRoot) {
      if (newRoot->val > high) newRoot = newRoot->left;
      else if (newRoot->val < low) newRoot = newRoot->right;
      else break;
    }
    if (!newRoot) return nullptr;
    // 新的根结点
    que.push(newRoot);
    while (!que.empty()) {
      TreeNode *cur = que.front();
      que.pop();
      if (cur->left) {
        TreeNode *temp = cur->left;
        if (temp->val >= low) {
          que.push(temp);
        }else {
          while (temp && temp->val < low)
            temp = temp->right;
          cur->left = temp;
          if (temp) {
            que.push(temp);
          }
        }
      }
      if (cur->right) {
        TreeNode *temp = cur->right;
        if (temp->val <= high) {
          que.push(temp);
        }else {
          while (temp && temp->val > high)
            temp = temp->left;
          cur->right = temp;
          if (temp) {
            que.push(temp);
          }
        }
      }
    }
    return newRoot;
  }
};

int main(int argc, char *argv[]) {
  TreeNode node[4];
  node[0].val = 3;
  node[1].val = 1;
  node[2].val = 2;
  node[3].val = 4;
  node[0].left = &node[1];
  node[0].right = &node[3];
  node[1].right = &node[2];

  Solution s;
  TreeNode *root = s.trimBST2(&node[0], 3, 4);

  return 0;
}
