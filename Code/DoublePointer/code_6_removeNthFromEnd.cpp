//
// Created by orange on 11/11/24.
//
#include "code_0_linklist.h"

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (--n && fast->next)
      fast = fast->next;
    while (fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next;
    }
    if (slow == head) {
      head = head->next;
    } else {
      prev->next = slow->next;
    }

    delete slow;
    return head;
  }
};

