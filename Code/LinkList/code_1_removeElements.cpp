//
// Created by orange on 11/10/24.
//
#include "code_0_linklist.h"


class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode temp(0, head);
    ListNode* cur = &temp;
    while (cur->next) {
      if (cur->next->val == val) {
        ListNode* del = cur->next;
        cur->next = del->next;
        delete del;
      } else {
        cur = cur->next;
      }
    }
    return temp.next;
  }
};


int main(int argc, char* argv[]) {



  return 0;
}