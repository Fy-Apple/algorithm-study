//
// Created by apple on 2024/10/21.
//

#include <iostream>
#include <unordered_set>
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
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> ptrSet;
    ListNode* p = head;
    while (p) {
      if (ptrSet.find(p) != ptrSet.end()) return true;
      ptrSet.emplace(p);
      p = p->next;
    }
    return false;
  }
};