//
// Created by apple on 2024/10/25.
//
#include <queue>
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfsTree(nums, 0, nums.size()-1);
  }
  TreeNode* dfsTree(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    const int mid = (l + r) / 2;
    const auto node = new TreeNode(nums[mid]);
    node->left = dfsTree(nums, l, mid - 1);
    node->right = dfsTree(nums, mid + 1, r);
    return node;
  }


};