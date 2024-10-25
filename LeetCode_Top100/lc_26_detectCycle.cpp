//
// Created by apple on 2024/10/21.
//

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
  ListNode *detectCycle1(ListNode *head) {
    unordered_set<ListNode*> ptrSet;
    ListNode* p = head;
    while (p) {
      if (ptrSet.find(p) != ptrSet.end()) return p;
      ptrSet.emplace(p);
      p = p->next;
    }
    return nullptr;
  }
  // 快慢指针
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;
    ListNode *slow = head, *fast = head, *ptr = head;
    while (true) {
      if (!fast || !fast->next)
        return nullptr;
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    while (ptr != slow) {
      slow = slow->next;
      ptr = ptr->next;
    }
    return ptr;
  }
};