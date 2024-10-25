//
// Created by apple on 2024/10/22.
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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* prev = nullptr;
    ListNode* p = head;
    head = head->next;
    while (p && p->next) {
      if (prev) {
        prev->next = p->next;
      }
      prev = p;
      p = p->next;
      prev->next = p->next;
      p->next = prev;
      p = prev->next;
    }
    return head;
  }
};