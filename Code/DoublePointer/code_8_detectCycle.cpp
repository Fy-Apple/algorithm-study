//
// Created by orange on 11/11/24.
//
#include "code_0_linklist.h"


class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    do {
      if (!fast || !fast->next) return nullptr;
      slow = slow->next;
      fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};