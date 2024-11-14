//
// Created by apple on 2024/10/27.
//
#include <iostream>
#include <vector>
using namespace std;

class SolutionGPT{
public:
void dfs(string& s, vector<vector<string>>& result, vector<string>& cur, int start) {
  if (start == s.size()) {  // 分割完成
    result.push_back(cur);
    return;
  }

  for (int size = 1; start + size <= s.size(); ++size) {
    // 检查当前子串是否是回文串
    int l = start, r = start + size - 1;
    bool isPalindrome = true;
    while (l < r) {
      if (s[l++] != s[r--]) {
        isPalindrome = false;
        break;
      }
    }

    if (isPalindrome) {
      cur.push_back(s.substr(start, size));
      dfs(s, result, cur, start + size);
      cur.pop_back();  // 恢复状态
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> result;
  vector<string> cur;
  dfs(s, result, cur, 0);
  return result;
}
};

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> cur;
    for (int size = 1; size <= s.size() ; ++size) {
      dfs(s, result, cur,  0, size);
    }
    return result;
  }



  void dfs(string& s, vector<vector<string>>& result, vector<string>& cur, const int i, const int size) {
    for (int l = i, r = i + size - 1; l < r; ++l, --r) {
      if (s.at(l) != s.at(r)) return;
    }
    cur.emplace_back(s.substr(i, size));
    if (i + size == s.size()) {
      result.push_back(cur);
      cur.pop_back();
      return;
    }
    for (int index = 1; index <= s.size() && i + size + index <= s.size(); ++index) {
      dfs(s, result, cur,  i + size, index);
    }
    cur.pop_back();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string test = "aab";
  for (const auto& v : s.partition(test)) {
    cout << "[";
    for (const auto& num : v) {
      cout << num << " ";
    }
    cout << "], " << endl;
  }
  return 0;
}
