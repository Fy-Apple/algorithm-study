//
// Created by orange on 11/11/24.
//
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    unordered_set<char> cSet;
    for (const auto& c : s) {
      cSet.emplace(c);
    }
    int firstIndex = 0;
    for (;firstIndex < s.size(); ++firstIndex) {
      if (cSet.count(s[firstIndex])) cSet.erase(s[firstIndex]);
      if (cSet.empty()) break;;
    }
    int subLen = firstIndex + 1;
    if (subLen == s.size()) return false;
    for (; firstIndex < s.size(); ++firstIndex) {
      int x = firstIndex + 1;
      bool tag = false;
      while (x + subLen < s.size() && s.substr(0, subLen) == s.substr(x, subLen)) {
        x += subLen;
        tag = true;
      }
      if (x == s.size() && tag) return true;
    }
    return false;
  }
};

int main(int agrc, char* agrv[]) {

  return 0;
}