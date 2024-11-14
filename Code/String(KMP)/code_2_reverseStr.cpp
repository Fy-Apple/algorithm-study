//
// Created by orange on 11/11/24.
//
#include <iostream>
using namespace std;
class Solution {
public:
  string reverseStr(string s, int k) {
    const int len = static_cast<int>(s.size());
    for (int i = 0; i < len; i += 2 * k) {
      int l = i, r = i + k - 1 == len ?  len - 1 : i + k - 1;
      while (l < r) {
        const char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        ++l;
        --r;
      }
    }
    return s;
  }
};

int main(int argc, char* argv[]) {

  return 0;
}