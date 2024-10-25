//
// Created by apple on 2024/10/17.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
  // 超时， 对于每一个字符都进行了一次遍历是不必要的
  vector<int> findAnagrams2(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;
    sort(p.begin(),p.end());
    for (int i = 0; i < s.size() - p.size() + 1; ++i) {
      string str = s.substr(i, p.size());
      sort(str.begin(),str.end());
      if (str == p) {
        result.push_back(i);
      }
    }

    return result;
  }
  // 对于窗口的左指针和右指针，左移出，右移入，可以把所有情况覆盖到，
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;

    vector<int> sVec(26);
    vector<int> pVec(26);
    for (int i = 0; i < p.size(); ++i) {
      ++sVec[s[i] - 'a'];
      ++pVec[p[i] - 'a'];
    }

    for (int i = 0; i < s.size() - p.size() + 1; ++i) {
      if (sVec == pVec) result.push_back(i);
      --sVec[s[i] - 'a'];
      if (i + p.size() < s.size()) ++sVec[s[i + p.size()] - 'a'];
    }

    return result;
  }
};


int main(int argc, char** argv) {
  Solution s;


  for (auto num : s.findAnagrams("cbaebabacd", "abc")) {
    cout << num << " ";
  }




  return 0;
}