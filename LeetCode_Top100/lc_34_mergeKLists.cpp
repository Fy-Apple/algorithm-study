//
// Created by apple on 2024/10/24.
//
#include <functional>
#include <iostream>
#include <queue>
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
  ListNode* mergeKLists2(vector<ListNode*>& lists) {
    vector<ListNode*> its;
    for (auto it = lists.begin(); it != lists.end(); ) {
      if (*it == nullptr) it = lists.erase(it);
      else {
        its.push_back(*it);
        ++it;
      }
    }
    if (its.empty()) return nullptr;
    ListNode vNode(-1);
    ListNode *vHead = &vNode;
    ListNode *cur = vHead;
    size_t itsNum = its.size();
    size_t minIndex = itsNum;
    while (true) {
      int minNum = INT_MAX;
      for (size_t index = 0; index < its.size(); ++index) {
        if (its[index] && its[index]->val < minNum) {
          minNum = its[index]->val;
          minIndex = index;
        }
      }
      if (minNum != INT_MAX) {
        cur->next = its[minIndex];
        cur = cur->next;
        its[minIndex] = its[minIndex]->next;
      }else {
        break;
      }
    }
    return  vHead->next;
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {

    auto cmp =
    [](const ListNode* a, const ListNode* b) {
      return a->val > b->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, std::function<bool(const ListNode*, ListNode*)>> heapQue(cmp);

    for (auto ptr : lists) {
      if (ptr != nullptr) heapQue.push(ptr);
    }
    ListNode vNode, *vHead = &vNode;
    while (!heapQue.empty()) {
      const auto ptr = heapQue.top();
      heapQue.pop();
      vHead->next = ptr;
      vHead = vHead->next;
      if (ptr->next) heapQue.push(ptr->next);
    }
    return vNode.next;
  }
};