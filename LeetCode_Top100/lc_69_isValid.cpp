//
// Created by apple on 2024/10/28.
//
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> charStack;
    unordered_map<char, char> cMap = {
      {')', '('},
      {']', '['},
      {'}', '{'}
    };
    for (const auto& c : s) {
      if (cMap.count(c) && !charStack.empty() && charStack.top() == cMap[c]) charStack.pop();
      else charStack.push(c);
    }
    if (charStack.empty()) return true;
    return false;
  }
};