//
// Created by orange on 11/10/24.
//
#include "code_0_linklist.h"

// 19.删除链表的倒数第N个节点
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *prev = nullptr, *slow = head, *fast = head;
    while (--n) fast = fast->next;
    while (fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next;
    }
    if (prev) prev->next = slow->next;
    delete slow;
    return head;
  }
};


int main(int argc, char *argv[]) {


  return 0;
}
