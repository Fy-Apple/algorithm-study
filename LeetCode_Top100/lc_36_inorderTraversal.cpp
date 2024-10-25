//
// Created by apple on 2024/10/25.
//
#include <iostream>
#include <stack>
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
      TreeNode* node = nodeStack.top();
      if (node->left) {
        nodeStack.push(node->left);
        node->left = nullptr;
        continue;
      }
      result.push_back(node->val);
      nodeStack.pop();
      if (node->right) {
        nodeStack.push(node->right);
      }
    }
    return result;
  }
  vector<int> inorderTraversal2(TreeNode* root) {
    inorder(root);
    return nums;
  }
  void inorder(TreeNode* node) {
    if (node) nums.push_back(node->val);
    else return;
    if (node->left) inorder(node->left);
    if (node->right) inorder(node->right);
  }
private:
  vector<int> nums;
};

int main(int argc, char** argv) {



  return 0;
}