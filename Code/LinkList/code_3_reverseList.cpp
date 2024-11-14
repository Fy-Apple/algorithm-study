//
// Created by orange on 11/10/24.
//
#include "code_0_linklist.h"

// 206.反转链表
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *prev = nullptr, *next = head->next;
    while (true) {
      head->next = prev;
      prev = head;
      if (next){
        head = next;
        next = next->next;
      }else break;
    }
    return head;
  }
  ListNode* reverseList2(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};