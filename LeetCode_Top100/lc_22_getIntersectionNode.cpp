//
// Created by apple on 2024/10/21.
//
#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    stack<ListNode*> stackA, stackB;
    ListNode *p = headA, *q = headB;
    if (!p || !q) return nullptr;
    while (p) {
      stackA.push(p);
      p = p->next;
    }
    while (q) {
      stackB.push(q);
      q = q->next;
    }
    ListNode* intersection = nullptr;
    while (!stackA.empty() && !stackB.empty() && stackA.top() == stackB.top()) {
      intersection = stackA.top();  // 更新相交的节点
      stackA.pop();
      stackB.pop();
    }
    return intersection;
  }
};



int main () {
  return 0;
}