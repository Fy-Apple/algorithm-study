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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    int carry = 0;
    int cur;
    ListNode first;
    ListNode* p = &first;
    while (l1 && l2) {
      cur = carry + l1->val + l2->val;
      carry = cur / 10;
      cur %= 10;
      ListNode* curNode = new ListNode(cur, nullptr);
      p->next = curNode;
      p = p->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (carry != 0 || l1 || l2) {
      if (l1) {
        cur = carry + l1->val;
        carry = cur / 10;
        cur %= 10;
        ListNode* curNode = new ListNode(cur, nullptr);
        p->next = curNode;
        p = p->next;
        l1 = l1->next;
      }else if (l2) {
        cur = carry + l2->val;
        carry = cur / 10;
        cur %= 10;
        ListNode* curNode = new ListNode(cur, nullptr);
        p->next = curNode;
        p = p->next;
        l2 = l2->next;
      }else {
        ListNode* curNode = new ListNode(carry, nullptr);
        p->next = curNode;
        carry = 0;
      }
    }
    return first.next;
  }
};