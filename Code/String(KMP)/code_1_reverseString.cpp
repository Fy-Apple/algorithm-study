//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      const char temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      ++l;
      --r;
    }
  }
};

int main(int argc, char* argv[]) {



  return 0;
}