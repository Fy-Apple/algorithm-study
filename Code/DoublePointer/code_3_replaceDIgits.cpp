//
// Created by orange on 11/11/24.
//
#include <iostream>
using namespace std;




int main(int agrc, char* argv[]) {
  string s;
  cin >> s;
  int count = 0;
  for (const char& c : s) {
    if (isdigit(c)) ++count;
  }
  const int len = static_cast<int>(s.size());
  s.resize(s.length() + count * 5);
  int index = static_cast<int>(s.size()) - 1;
  for (int i = len - 1; i >= 0; --i) {
    if (isalpha(s[i])) {
      s[index--] = s[i];
    }else {
      s[index--] = 'r';
      s[index--] = 'e';
      s[index--] = 'b';
      s[index--] = 'm';
      s[index--] = 'u';
      s[index--] = 'n';
    }
  }
  cout << s;
  return 0;
}