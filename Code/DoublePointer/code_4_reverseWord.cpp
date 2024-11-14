//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string result;
    for (int i = s.length() - 1; i >= 0; --i) {
      while (i >= 0 && isspace(s[i])) --i;
      int l = i;
      while (l >= 0 && !isspace(s[l])) --l;
      if (!isspace(s[l + 1])) {
        result.append(s.substr(l + 1, i - l));
        result.push_back(' ');
      }
      i = l;
    }
    if (!result.empty()) result.pop_back();
    return result;
  }
};