//
// Created by orange on 11/12/24.
//
#include <unordered_map>

#include "code_0_binarytree.h"


class Solution {
private:
  unordered_map<int, int> inIndexMap;
public:
  //105. 从前序与中序遍历序列构造二叉树
  TreeNode* preBuild(vector<int>& preorder, vector<int>& inorder, int inL, int inR, int preL, int preR) {
    const int inIndex = inIndexMap[preorder[preL]];
    const auto root = new TreeNode(preorder[preL]);
    root->left = inIndex == inL ? nullptr : preBuild(preorder, inorder, inL, inIndex - 1, preL + 1, preL + inIndex - inL);
    root->right = inIndex == inR ? nullptr : preBuild(preorder, inorder, inIndex + 1, inR, preL + inIndex - inL + 1, preR);
    return root;
  }
  TreeNode* preBuildTree(vector<int>& preorder, vector<int>& inorder) {
    if (inorder.empty()) return nullptr;
    for (int i = 0; i < inorder.size(); ++i) inIndexMap[inorder[i]] = i;
    return preBuild(preorder, inorder, 0, static_cast<int>(inorder.size()) - 1, 0, static_cast<int>(preorder.size()) - 1);
  }





  // 106. 从中序与后序遍历序列构造二叉树
  TreeNode* postBuild(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postL, int postR) {
    int inIndex = inL;
    for (;inIndex <= inR; ++inIndex) {
      if (inorder[inIndex] == postorder[postR]) break;
    }
    TreeNode *root = new TreeNode(postorder[postR]);
    root->left = inIndex == inL ? nullptr : postBuild(inorder, postorder, inL, inIndex - 1, postL, postL + inIndex - inL - 1);
    root->right = inIndex == inR ? nullptr : postBuild(inorder, postorder, inIndex + 1, inR, postL + inIndex - inL, postR - 1);
    return root;
  }
  TreeNode* postBuildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) return nullptr;
    TreeNode *root = postBuild(inorder, postorder, 0, static_cast<int>(inorder.size()) - 1, 0, static_cast<int>(postorder.size()) - 1);
    return root;
  }


  //
  TreeNode* layerBuildTree(vector<int>& inorder, vector<int>& postorder) {
    return nullptr;
  }
};