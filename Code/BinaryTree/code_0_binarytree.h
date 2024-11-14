//
// Created by Orange on 2024/11/13.
//

#ifndef CODE_0_BINARYTREE_H
#define CODE_0_BINARYTREE_H

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
#include <vector>
#include <string>


#endif //CODE_0_BINARYTREE_H
