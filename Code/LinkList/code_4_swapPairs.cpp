//
// Created by orange on 11/10/24.
//
#include "code_0_linklist.h"

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *newHead = head->next;
    ListNode *prev = nullptr, *next = head->next->next;
    while (true) {
      if (prev) prev->next = head->next;
      head->next->next = head;
      head->next = next;
      prev = head;
      head = head->next;
      next = head;
      if (!next || !next->next) break;
      next = next->next->next;
    }
    return newHead;
  }
};


int main(int argc, char *argv[]) {

  return 0;
}
