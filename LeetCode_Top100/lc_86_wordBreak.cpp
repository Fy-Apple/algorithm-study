//
// Created by Orange on 2024/10/31.
//
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_multiset<string> wordSet;
    for (const auto& str : wordDict)
      wordSet.emplace(str);
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i < s.size(); ++i) {
      if (!dp[i]) continue;
      for (int j = i; j < s.size(); ++j)
        if (wordSet.count(s.substr(i, j - i + 1))) {
          dp[j + 1] = true;
        }
    }
    return dp[s.size()];
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  vector<string> test = {"aaaa", "aaa"};
  cout << s.wordBreak("aaaaaaa", test);

  return 0;
}
