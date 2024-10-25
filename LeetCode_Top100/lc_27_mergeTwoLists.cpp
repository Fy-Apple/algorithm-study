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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    ListNode *first, *p;
    if (list1->val < list2->val) {
      first = list1;
      list1 = list1->next;
    }else {
      first = list2;
      list2 = list2->next;
    }
    p = first;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        p->next = list1;
        list1 = list1->next;
      }else {
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }
    while (list1) {
      p->next = list1;
      p = p->next;
      list1 = list1->next;
    }
    while (list2) {
      p->next = list2;
      p = p->next;
      list2 = list2->next;
    }
    return first;
  }
};