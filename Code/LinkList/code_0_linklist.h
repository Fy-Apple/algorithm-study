//
// Created by orange on 11/10/24.
//

#ifndef CODE_0_LINKLIST_H
#define CODE_0_LINKLIST_H


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};




#endif //CODE_0_LINKLIST_H
