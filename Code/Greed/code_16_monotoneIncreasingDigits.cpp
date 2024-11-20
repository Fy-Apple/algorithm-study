//
// Created by Orange on 2024/11/20.
//
#include "code_0_headers.h"
// 738. 单调递增的数字
class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    if (n < 10) return n;
    const string s = to_string(n);
    string result = {s[0]};
    bool dec = false;
    for (int i = 1; i < s.size(); ++i) {
      if (dec) {
        result.push_back('9');
      }
      else if (s[i] >= result.back()) {
        result.push_back(s[i]);
      }else {
        result.push_back('0');
        int index = static_cast<int>(result.size()) - 1;
        while (index >= 1 && result[index] < result[index - 1]) {
          result[index] = '9';
          --result[index - 1];
          --index;
        }
        dec = true;
      }
    }
    return stoi(result);
  }
  // 优化
  int monotoneIncreasingDigits2(int n) {
    string s = to_string(n);
    int flag = static_cast<int>(s.size());
    for (int i = flag - 1; i > 0; --i) {
      if (s[i - 1] > s[i]) {
        flag = i;
        --s[i - 1];
      }
    }
    for (int i = flag; i < s.size(); ++i) {
      s[i] = '9';
    }
    return stoi(s);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.monotoneIncreasingDigits(989998);
  return 0;

}
