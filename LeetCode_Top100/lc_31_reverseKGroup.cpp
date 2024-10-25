//
// Created by apple on 2024/10/23.
//
#include <iostream>
#include <mmintrin.h>
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    int num = k;
    ListNode *p = head, *kfirst = head, *prev = nullptr, *next = nullptr,
             *newHead = nullptr;
    while (true) {
      while (--num && p) {
        p = p->next;
      }
      if (num == 0 && p) {
        // 反转kfirst - > p
        next = p->next; // 后续链表的第一个节点
        if (prev)
          prev->next = p; // 前驱链表的最后一个节点
        prev = kfirst;      // 更新前驱链表
        while (kfirst != p) {
          ListNode* temp = kfirst->next;
          kfirst->next = next;
          next = kfirst;
          kfirst = temp;
        }
        kfirst->next = next;
        if (newHead == nullptr)
          newHead = p;
        num = k;
        kfirst = prev->next;
        p = kfirst;
      } else {
        break;
      }
    }
    return newHead == nullptr ? head : newHead;

  }
};