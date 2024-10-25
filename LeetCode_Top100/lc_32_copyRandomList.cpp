//
// Created by apple on 2024/10/23.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    vector<int> addDist;
    vector<Node*> addVec;
    if (!head) return  nullptr;
    Node* p = head, *prev = nullptr,*newHead = nullptr;
    for (int i = 0; p; ++i, p = p->next) {
      Node* temp = p->random;
      addDist.push_back(0);
      while (temp) {
        temp = temp->next;
        ++addDist[i];
      }
      const auto newp = new Node(p->val);
      addVec.push_back(newp);
      if (prev) prev->next = newp;
      if (newHead == nullptr) newHead = newp;
      prev = newp;
    }
    prev->next = nullptr;
    // 初始化random指针
    p = newHead;
    for (int i = 0; p; ++i, p = p->next) {
      p->random = addDist[i] == 0 ? nullptr : addVec[addVec.size() - addDist[i]];
    }
    return newHead;
  }
};