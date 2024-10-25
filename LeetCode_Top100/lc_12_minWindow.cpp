//
// Created by apple on 2024/10/18.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
private:
  unordered_map<char, int> str, back;
  bool check() {
    for (const auto& p : back) {
      if (str[p.first] < p.second) return false;
    }
    return true;
  }
public:
  // 超时理由：未处理左指针
  string minWindow2(string s, string t) {
    if (s.size() < t.size()) return "";
    unordered_map<char, int> strMap;
    unordered_map<char, int> backMap;
    for (const char& c : t) {
      ++backMap[c];
      strMap[c] = 0;
    }
    int minIndex = s.size();
    int minLength = s.size();;
    for (int i = 0; i <= s.size() - t.size(); ++i) {
      if (backMap.find(s[i]) != backMap.end()) {
        for (int j = i; j < s.size() && j < i + minLength; ++j) {
          if (backMap.find(s[j]) != backMap.end()) ++strMap[s[j]];

          bool equal = true;
          for (auto c : backMap) {
            if (strMap[c.first] < c.second) {
              equal = false;
              break;
            }
          }
          if (equal) {
            // 移动左边界
            bool move = false;
            while (backMap.find(s[i]) == backMap.end() || strMap[s[i]] > backMap[s[i]]) {
              if (strMap[s[i]] > backMap[s[i]]) --strMap[s[i]];
              ++i;
              move = true;
            }
            if (minLength >= j - i + 1) {
              minIndex = i;
              minLength = j - i + 1;
            }
            if (move) --i;
            break;
          }
        }
        for (auto& p : strMap) {
          p.second = 0;
        }
      }
    }
    if (minIndex != s.size()) {
      return s.substr(minIndex, minLength);
    }
    return "";
  }
  string minWindow(string s, string t) {
    for (const auto& c : t) {
      ++back[c];
      str[c] = 0;
    }
    for (int i = 0; i < t.size(); ++i) {
      if (back.find(s[i]) != back.end()) {
        ++str[s[i]];
      }
    }
    if (check()) return s.substr(0, t.size());

    int minIndex = s.size(), minLength = s.size();
    int l = 0, r = static_cast<int>(t.size()) - 1;
    while (r < s.size()) {
      if (back.find(s[++r]) != back.end()) {
        ++str[s[r]];
      }
      for (auto p : str) {
        cout << p.first << ":" << p.second << ", " ;
      }
      cout << endl;
      while (check() && l <= r) {
        cout << minLength << ", " << r << ", " << l;
        if (minLength >= r - l + 1) {
          minLength = r - l + 1;
          minIndex = l;
        }
        if (back.find(s[l]) != back.end()) {
          --str[s[l]];
        }
        ++l;
      }
    }
    if (minIndex < s.size()) return s.substr(minIndex, minLength);
    return "";
  }



};


int main(int argc, char** argv) {
  Solution s;
  cout << s.minWindow("abc", "ac");


  return 0;
}