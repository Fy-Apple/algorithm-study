//
// Created by orange on 11/11/24.
//
#include <stack>
#include <string>
using namespace std;

// 20. 有效的括号
class Solution {
public:
  bool isValid(string s) {
    stack<char> cS;
    for (const char& c : s) {
      if (c == '(' || c == '{' || c == '[') {
        cS.push(c);
      }else if (c == ')' && !cS.empty() && cS.top() == '(') {
        cS.pop();
      }else if (c == '}' && !cS.empty() && cS.top() == '{') {
        cS.pop();
      }else if (c == ']' && !cS.empty() && cS.top() == '[') {
        cS.pop();
      }else {
        return false;
      }
    }
    return cS.empty();
  }
};