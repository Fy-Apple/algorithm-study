//
// Created by orange on 11/11/24.
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
    if (!head) return nullptr;
    ListNode *prev = nullptr, *next = head->next;
    while (head) {
      head->next = prev;
      prev = head;
      if (next) {
        head = next;
        next = next->next;
      }else {
        break;
      }
    }
    return head;
  }
};