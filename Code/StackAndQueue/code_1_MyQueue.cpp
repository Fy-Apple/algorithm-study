//
// Created by orange on 11/11/24.
//
#include <stack>
#include <vector>
using namespace std;
class MyQueue {
private:
  stack<int> s1, s2;
public:
  MyQueue() {
  }

  void push(int x) {
    s1.push(x);
  }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int x = s2.top();
    s2.pop();
    return x;
  }

  int peek() {
    int x = pop();
    s2.push(x);
    return x;
  }

  bool empty() {
    return  s1.empty() && s2.empty();
  }
};