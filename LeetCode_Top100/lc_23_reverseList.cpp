//
// Created by apple on 2024/10/21.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p = head->next;
    ListNode* q;
    head->next = nullptr;
    while(p) {
      q = p;
      p = p->next;
      q->next = head;
      head = q;
    }
    return p;
  }
};