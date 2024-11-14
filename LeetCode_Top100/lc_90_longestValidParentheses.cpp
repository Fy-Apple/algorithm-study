//
// Created by orange on 11/4/24.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> paS;
    int maxLen = 0;
    paS.push(-1); // 用于处理边界条件

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        paS.push(i); // 压入左括号的位置
      } else {
        paS.pop(); // 弹出匹配的左括号
        if (paS.empty()) {
          paS.push(i); // 没有匹配，记录当前右括号的位置
        } else {
          maxLen = max(maxLen, i - paS.top()); // 更新最大长度
        }
      }
    }
    return maxLen;
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  string test = "(()()";
  cout << s.longestValidParentheses(test);

  return 0;
}
