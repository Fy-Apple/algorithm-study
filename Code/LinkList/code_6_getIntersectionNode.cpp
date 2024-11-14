//
// Created by orange on 11/10/24.
//
#include "code_0_linklist.h"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    bool tag = false;
    while (headA != headB) {
      if (headA->next) headA = headA->next;
      else {
        if (tag) return nullptr;
        tag = true;
        headA = headB;
      }
      if (headB->next) headB = headB->next;
      else headB = headA;
    }
    return headA;
  }
};

