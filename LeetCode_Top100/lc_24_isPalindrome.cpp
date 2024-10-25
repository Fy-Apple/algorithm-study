//
// Created by apple on 2024/10/21.
//
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    vector<int> numVec;
    ListNode* p = head;
    while (p) {
      numVec.push_back(p->val);
      p = p->next;
    }
    for (int i = 0, j = numVec.size() - 1; i < j; ++i, --j) {
      if (numVec[i] != numVec[j])
        return false;
    }
    return true;
  }
};