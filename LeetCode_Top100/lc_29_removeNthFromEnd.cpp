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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = head, *q = head, *prev = q;
    while (--n && p) {
      p = p->next;
      if (!p) return nullptr;
    }
    while (p->next) {
      p = p->next;
      prev = q;
      q = q->next;
    }
    if (prev != q) {
      prev->next = q->next;
      delete q;
    }else {
      head = head->next;
      delete q;
    }
    return  head;
  }
};