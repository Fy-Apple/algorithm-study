//
// Created by orange on 11/4/24.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  pair<int, int> longestPal(string& s, int i, int j) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
      --i;
      ++j;
    }
    return {++i, --j};
  }
  string longestPalindrome(string s) {
    if (s.size() < 2) return s;
    int start = 0, end = 0;
    for (int i = 1; i < s.size(); ++i) {
      pair<int, int> pair1 = longestPal(s, i, i);
      pair<int, int> pair2 = longestPal(s, i, i + 1);
      if (pair1.second - pair1.first > end - start) {
        start = pair1.first;
        end = pair1.second;
      }
      if (pair2.second - pair2.first > end - start) {
        start = pair2.first;
        end = pair2.second;
      }
    }
    return s.substr(start, end - start + 1);
  }


  string longestPalindrome2(string s) {
    vector<int> dp(s.size(), 0);
    int maxIndex = 0;
    for (int i = 1; i < s.size(); ++i) {
      dp[i] = i;
      if (dp[i - 1] != i - 1) {
        if (dp[i - 1] >= 1 &&s[dp[i - 1] - 1] == s[i])
          dp[i] = dp[i - 1] - 1;
        if (s[dp[i - 1]] == s[i]) {
          bool tag = true;
          for (int j = dp[i - 1] + 1; j <i; ++j) {
            if (s[j] != s[i]) {
              tag = false;
              break;
            }
          }
          if (tag) dp[i] = dp[i - 1];
        }
      }else {
        if (s[i] == s[i - 1]) dp[i] = i - 1;
        if (i > 1 && s[i] == s[i - 2]) dp[i] = i - 2;
      }
      maxIndex = i - dp[i] > maxIndex - dp[maxIndex] ? i : maxIndex;
    }
    return s.substr(dp[maxIndex], maxIndex - dp[maxIndex] + 1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.longestPalindrome2("ababababababa");

  return 0;
}



