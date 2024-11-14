//
// Created by orange on 11/12/24.
//
#include <stack>
#include <unordered_map>

#include "code_0_binarytree.h"
class Solution {
private:
  unordered_map<int, int> indexMap;
public:
  //654. 最大二叉树
  TreeNode* build(vector<int>& nums, int l, int r) {
    int index = l;
    for(int i = l; i <= r; ++i) {
      if (nums[index] < nums[i]) index = i;
    }
    auto const root = new TreeNode(nums[index]);
    root->left = index == l ? nullptr : build(nums, l, index - 1);
    root->right = index == r ?nullptr : build(nums, index + 1, r);
    return root;
  }

  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //for (int i = 0; i < nums.size(); ++i) indexMap[nums[i]] = i;
    return build(nums, 0, static_cast<int>(nums.size()) - 1);
  }

  // 单调栈
  TreeNode* constructMaximumBinaryTree2(vector<int>& nums) {
    stack<int> stk;
    vector<int> left(nums.size(), -1);
    vector<int> right(nums.size(), -1);
    vector<TreeNode*> nodes(nums.size(), nullptr);
    for (int i = 0; i <nums.size(); ++i) {
      nodes[i] = new TreeNode(nums[i]);
      while (!stk.empty() && nums[i] > nums[stk.top()]) {
        right[stk.top()] = i;
        stk.pop();
      }
      if (!stk.empty()) {
        left[i] = stk.top();
      }
      stk.push(i);
    }
    TreeNode *root = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
      if (left[i] == -1 && right[i] == -1) {
        root = nodes[i];
      }
      else if (left[i] == -1 || (nums[left[i]] > nums[right[i]])){
        nodes[right[i]]->left = nodes[i];
      }
      else {
        nodes[left[i]]->right = nodes[i];
      }
    }
    return root;
  }
};