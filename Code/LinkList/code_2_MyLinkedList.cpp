//
// Created by orange on 11/10/24.
//
#include <unordered_map>

#include "code_0_linklist.h"


class MyLinkedList {
private:
  ListNode *head, *tail;
  int num;
public:
  MyLinkedList() : head(new ListNode), tail(head), num(0) {}


  int get(int index) {
    if (index < 0 || index >= num)  // 如果 index >= num，则越界，返回 -1
      return -1;
    ListNode* p = head->next;
    while (index--) p = p->next;  // 逐个节点遍历
    return p->val;
  }

  void addAtHead(int val) {
    addAtIndex(0, val);
  }

  void addAtTail(int val) {
    ListNode* newNode = new ListNode(val, nullptr);
    tail->next = newNode;
    tail = newNode;
    ++num;
  }


  void addAtIndex(int index, int val) {
    if (index < 0 || index > num)  // 应该是 index > num 允许在尾部添加
      return;
    ListNode *p = head;
    while (index--) p = p->next;
    ListNode *newNode = new ListNode(val, p->next);
    p->next = newNode;
    ++num;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= num) return;
    ListNode *p = head;
    while (index--) p = p->next;
    ListNode *t = p->next;
    p->next = p->next->next;
    delete t;
    --num;
  }
};


