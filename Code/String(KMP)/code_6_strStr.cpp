//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 28. 实现 strStr()
class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.size(); ++i) {
      int index = i,j = 0;
      while (index < haystack.size() && j < needle.size() && haystack[index] == needle[j]) {
        ++index;
        ++j;
      }
      if (j == needle.size()) return i;
    }
    return -1;
  }
  int strStrKMP(string haystack, string needle) {
    vector<int> next(needle.size(), -1);
    next[1] = 0;

    for (int i = 0; i < haystack.size(); ++i) {

    }
  }
};

int main() {

  return 0;
}