//
// Created by apple on 2024/10/27.
//
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  void dfs(vector<string>& result, string& cur, int left, int right) {
    if (left == 0 && right == 0) {
      result.push_back(cur);
      return;
    }
    if (left > 0) {
      cur.push_back('(');
      dfs(result, cur, left - 1, right);
      cur.pop_back();
    }
    if (right > left) {
      cur.push_back(')');
      dfs(result, cur, left, right - 1);
      cur.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string cur;
    dfs(result, cur, n, n);
    return result;
  }

  vector<string> generateParenthesis3(int n) {
    if (n == 0) return {};
    set<string> result;
    string cur = "(";
    dfs3(result, n - 1, n, 0, 0, cur);
    return vector<string>(result.begin(), result.end());
  }
  void dfs3(set<string>& result, const int left, const int right, const int l, const  int r, string& cur) {
    if (l == left && r == right) {
      stack<char> checkStack;
      for (const auto& c : cur) {
        if (!checkStack.empty() && c == ')' && checkStack.top() == '(') {
          checkStack.pop();
        }else {
          checkStack.push(c);
        }
      }
      if (checkStack.empty()) {
        result.emplace(cur);
      }
      return;
    }
    if (l < left) {
      cur.push_back('(');
      dfs3(result, left, right, l + 1, r, cur);
      cur.pop_back();
    }
    if (r < right) {
      cur.push_back(')');
      dfs3(result, left, right, l, r + 1, cur);
      cur.pop_back();
    }
  }

  vector<string> generateParenthesis2(int n) {
    if (n == 0) return {};
    set<string> result;
    string cur;
    cur.push_back('(');
    vector<pair<bool, bool>> valVec(n * 2 -1, {false, false});//')'
    for (int i = 0; i < n - 1; ++i) valVec[i].first = true;//'('
    dfs2(valVec, result, cur);
    return vector<string>(result.begin(), result.end());
  }

  void dfs2(vector<pair<bool, bool>>& valVec, set<string>& result, string& cur) {
    if (cur.size() - 1 == valVec.size()) {
      stack<char> checkStack;
      for (const auto& c : cur) {
        if (!checkStack.empty() && c == ')' && checkStack.top() == '(') {
          checkStack.pop();
        }else {
          checkStack.push(c);
        }
      }
      if (checkStack.empty()) {
        result.emplace(cur);
      }
      return;
    }
    for (int i = 0; i < valVec.size(); ++i) {
      if (valVec[i].second == false) {
        valVec[i].second = true;
        cur.push_back(valVec[i].first ? '(' : ')');
        dfs2(valVec, result, cur);
        cur.pop_back();
        valVec[i].second = false;
      }
    }
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {2,3,6,7};
  cout << "[";
  for (const auto& v : s.generateParenthesis(6)) {
    cout << v << ", ";
  }
  cout << "], " << endl;
}
