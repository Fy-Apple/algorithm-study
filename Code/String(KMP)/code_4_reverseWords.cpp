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
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
      while (i >= 0 && isspace(s[i])) --i;
      int l = i;
      while (l >= 0 && !isspace(s[l])) --l;
      if (!isspace(s[l + 1])) {
        result.append(s.substr(l + 1, i - l));
        result.push_back(' ');
      }
      i = l;
      if (i <= 0) break;
    }
    if (!result.empty()) result.pop_back();
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  cout << s.reverseWords("  hello world  ");
  return 0;
}