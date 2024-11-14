//
// Created by Orange on 2024/11/13.
//
#include <queue>

#include "code_0_binarytree.h"

class Solution {
public:
  // 108. 将有序数组转换为二叉搜索树
  TreeNode* build(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    const int mid = l + (r - l) / 2;
    auto const midNode = new TreeNode(nums[mid]);
    midNode->left = build(nums, l, mid - 1);
    midNode->right = build(nums, mid + 1, r);
    return midNode;
  }
  TreeNode* sortedArrayToBST2(vector<int>& nums) {
    return build(nums, 0, static_cast<int>(nums.size()) - 1);
  }

};