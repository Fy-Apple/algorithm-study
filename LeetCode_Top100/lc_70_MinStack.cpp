#include <algorithm>
#include <stack>
#include <unordered_map>
//
// Created by apple on 2024/10/29.
//
class MinStack {
private:
  std::stack<int> valStack;
  std::stack<int> minStack;
public:
  MinStack() {

  }
  void push(int val) {
    if (valStack.empty() || minStack.top() <= val) {
      minStack.push(val);
    }
    valStack.push(val);
  }

  void pop() {
    if (valStack.empty()) return;
    if (valStack.top() == minStack.top()) {
      minStack.pop();
    }
    valStack.pop();
  }

  int top() {
    if (valStack.empty()) return -1;
    return valStack.top();
  }

  int getMin() {
    if (valStack.empty()) return -1;
    return minStack.top();
  }
};


int main(int argc, char *argv[]) {

  return 0;
}
