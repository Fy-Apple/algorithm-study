//
// Created by orange on 11/11/24.
//
#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<string> cS;
    for (const string& s : tokens) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        const int num2 = stoi(cS.top());
        cS.pop();
        const int num1 = stoi(cS.top());
        cS.pop();
        int newNum;
        if (s == "+") newNum = num1 + num2;
        else if (s == "-") newNum = num1 - num2;
        else if (s == "*") newNum = num1 * num2;
        else newNum = num1 / num2;
        cS.push(to_string(newNum));
      }else {
        cS.push(s);
      }
    }
    return stoi(cS.top());
  }
};

int main(int argc, char *argv[]) {
  vector<string> test = {"4","13","5","/","+"};
  Solution s;
  cout << s.evalRPN(test);
  return 0;
}

