//
// Created by orange on 11/11/24.
//
#include <iostream>
using namespace std;




int main(int agrc, char* argv[]) {
  string s;
  cin >> s;
  string result;
  for (const auto& c : s) {
    if (isdigit(c)) {
      result.append("number");
    }else if (isalpha(c)) {
      result.push_back(c);
    }
  }
  cout << result;
  return 0;
}