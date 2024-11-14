//
// Created by apple on 2024/10/29.
//
#include <ios>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
  int dfsDecode(string& s, int index, string& result) {
    string insertString;
    string insertNum;
    while (isdigit(s[index])) insertNum.push_back(s[index++]);
    ++index;
    while (s[index] != ']') {
      if (isalpha(s[index])) {
        insertString.push_back(s[index]);
      }else {
        index = dfsDecode(s, index, insertString);
      }
      ++index;
    }
    int num = stoi(insertNum);
    while (num--) result.append(insertString);
    return index;
  }
  string decodeString(string s) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
      if (isalpha(s[i])) {
        result.push_back(s[i]);
      }
      else {
        i = dfsDecode(s, i, result);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.decodeString("b3[a2[c]]");
  return 0;
}
