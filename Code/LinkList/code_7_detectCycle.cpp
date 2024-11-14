//
// Created by orange on 11/10/24.
//
#include "code_0_linklist.h"

// 142.环形链表II
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    // 2(a + b) = a + n(b + c) + b
    // a = (n - 1)(b + c) + c
    if (!head) return nullptr;
    ListNode *slow = head,*fast = head;
    do {
      if (!fast->next || !fast->next->next) return nullptr;
      slow = slow->next;
      fast = fast->next->next;
    } while (slow != fast);
    while (head != slow) {
      head = head->next;
      slow = slow->next;
    }
    return head;
  }
};


int main(int agrc, char* argv[]) {


  return 0;
}