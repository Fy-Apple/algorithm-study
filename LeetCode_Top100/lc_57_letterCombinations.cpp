//
// Created by apple on 2024/10/26.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;
    unordered_map<char, string> charMap = {
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"},
    };
    string cur;
    dfs(digits, charMap, 0, result, cur);
    return result;
  }
  void dfs(string& digits,  unordered_map<char, string>& charMap, int index, vector<string>& result, string& cur) {
    if (index == digits.size()) {
      result.emplace_back(cur);
      return;
    }
    if (digits.at(index) != '1') {
      for (const auto& c : charMap[digits.at(index)]) {
        cur.push_back(c);
        dfs(digits, charMap, index + 1, result, cur);
        cur.pop_back();
      }
    }else {
      dfs(digits, charMap, index + 1, result, cur);
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string test = "23";
  for (const auto& s : s.letterCombinations(test)) {
    cout << "'" << s  << "', ";
  }
  return 0;
}
