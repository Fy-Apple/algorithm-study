//
// Created by orange on 11/11/24.
//
#include "code_0_linklist.h"

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    ListNode *p = headA, *q = headB;
    while (p != q) {
      p = p == nullptr ? headB : p->next;
      q = q == nullptr ? headA : q->next;
    }
    return p;
  }
};