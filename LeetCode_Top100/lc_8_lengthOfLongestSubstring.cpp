//
// Created by apple on 2024/10/17.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() < 2) return static_cast<int>(s.length());
    unordered_set<char> indexSet;
    int maxLength = 0;
    for (int i = 0,j = 0; i < s.length(); ++i) {
      if (i != 0) indexSet.erase(s[i - 1]);
      while (j < s.length() && indexSet.find(s[j]) == indexSet.end()) {
        indexSet.emplace(s[j]);
        ++j;
      }
      maxLength = max(maxLength, j - i);
      cout << endl;
    }

    return maxLength;
  }
};


int main(int argc, char** argv) {
  Solution s;


  cout << s.lengthOfLongestSubstring("bbbbb");




  return 0;
}