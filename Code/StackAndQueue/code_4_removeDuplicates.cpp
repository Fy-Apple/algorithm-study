//
// Created by orange on 11/11/24.
//
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

// 1047. 删除字符串中的所有相邻重复项
class Solution {
public:
  string removeDuplicates(string s) {
    string result;
    for (const char& c : s) {
      if (!result.empty() && c == result.back()) {
        result.pop_back();
      }else {
        result.push_back(c);
      }
    }
    return result;
  }
};