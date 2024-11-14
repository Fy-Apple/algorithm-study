//
// Created by orange on 11/11/24.
//
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class MyStack {
private:
  queue<int> q1, q2;

public:
  MyStack() {

  }

  void push(int x) {
    if (!q1.empty()) q1.push(x);
    else q2.push(x);
  }

  int pop() {
    if (!q1.empty()) {
      while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
      }
      int x = q1.front();
      q1.pop();
      return x;
    }
    if (!q2.empty()) {
      while (q2.size() != 1) {
        q1.push(q2.front());
        q2.pop();
      }
      int x = q2.front();
      q2.pop();
      return x;
    }
    return -1;
  }

  int top() {
    int x = pop();
    push(x);
    return x;
  }

  bool empty() {
    return q1.empty() && q2.empty();
  }
};