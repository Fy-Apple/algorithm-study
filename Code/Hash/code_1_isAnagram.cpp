//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//242.有效的字母异位词
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> charMap;
    for (auto& c : s) ++charMap[c];
    for (auto&c : t) --charMap[c];
    for (auto [k, v] : charMap) if (v != 0) return false;
    return true;
  }
  bool isAnagram2 (string s, string t) {
    vector<int> cV(26, 0);
    for (const auto& c : s) {
      ++cV[c - 'a'];
    }
    for (const auto& c : t) {
      --cV[c - 'a'];
      if (cV[c - 'a'] < 0) return false;
    }
    return true;
  }
};


int main(int argc, char* argv[]) {



  return 0;
}