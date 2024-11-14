//
// Created by orange on 11/11/24.
//
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


// 右旋字符串 非lc
int main(int argc, char* argv[]) {
  int k;
  string s;
  cin >> k >> s;
  reverse(s.begin(), s.end() - k);
  reverse(s.end() - k, s.end());
  reverse(s.begin(), s.end());
  cout << s;
  return 0;
}