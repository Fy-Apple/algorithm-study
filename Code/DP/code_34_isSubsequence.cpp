//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 392. 判断子序列
class Solution {
  vector<vector<int>> dp;
  string inner;
public:
  // 双指针
  bool isSubsequence(string s, string t) {
    int p1 = 0, p2 = 0;
    for (; p1 < s.size() && p2 < t.size(); ++p2) {
      if (s[p1] == t[p2]) ++p1;
    }
    return p1 == s.size();
  }

  // dp
  bool isSubsequence2(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size(); ++j) {
        dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + 1 : dp[i][j - 1];
      }
    }
    return dp.back().back() == s.size();
  }

  // 空间压缩
  bool isSubsequence3(string s, string t) {
    vector<int> dp(t.size() + 1, 0);
    for (int i = 1; i <= s.size(); ++i) {
      int prev = 0;
      for (int j = 1; j <= t.size(); ++j) {
        const int temp = dp[j];
        dp[j] = s[i - 1] == t[j - 1] ? prev + 1 : dp[j - 1];
        prev = temp;
      }
    }
    return dp.back() == s.size();
  }

  void init(string& origin) {
    inner = std::move(origin);
    dp.resize(inner.size() + 1, vector<int>(26, -1));
    // inner.insert(inner.begin(), ' ');
    for (char c = 'a'; c <= 'z'; ++c) {
      int nextPos = -1;
      for (int j = static_cast<int>(inner.size()); j >= 0; --j) {
        dp[j][c - 'a'] = nextPos;
        if (c == inner[j - 1]) nextPos = j;
      }
    }
  }
  // 大量数据统计
  bool isSub(string s) {
    int index = 0;
    for (const auto& c : s) {
      index = dp[index][c - 'a'];
      if (index == -1) return false;
    }
    return true;
  }
};

int main(int argc, char *argv[])
{
  string test = "axxbxxxcxxhxdxksjksjkenbjakncjkacjfajsdioaisdjagaskasdklh";
  Solution s;
  s.init(test);

  cout << s.isSub("abcdefg") << endl;

  cout << s.isSub("abc") << endl;

  cout << s.isSub("afg") << endl;

  cout << s.isSub("abcdefgho") << endl;

  cout << s.isSub("ssssss") << endl;

  return 0;
}
