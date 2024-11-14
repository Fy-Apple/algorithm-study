//
// Created by orange on 11/5/24.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int maxLen = 0;
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); ++i) {
      for (int j = 1; j <= text2.size(); ++j) {
        dp[i][j] = dp[i - 1][j - 1];
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }else {
          int index = i - 2;
          while (index >= 0) {
            if (text1[index] == text2[j - 1]) {
              dp[i][j] = max(dp[i][j], dp[index][j - 1] + 1);
            }
            --index;
          }
          index = j - 2;
          while (index >= 0) {
            if (text1[i - 1] == text2[index]) {
              dp[i][j] = max(dp[i][j], dp[i - 1][index] + 1);
            }
            --index;
          }
        }
        maxLen = max(maxLen, dp[i][j]);
      }
    }
    return maxLen;
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  cout << s.longestCommonSubsequence("hofubmnylkra", "pqhgxgdofcvmr");
}
