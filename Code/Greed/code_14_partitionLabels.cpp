//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

// 763. 划分字母区间
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<pair<int, int>> groups(26, {-1, 0});
    int gn = 0;
    for (const auto& c : s) {
      const int number = groups[c - 'a'].first;
      if (number == -1) {
        groups[c - 'a'].first = ++gn;
      }else {
        for (auto& [fi, se] : groups) {
          if (fi > number && fi <= gn) fi = number;
        }
        gn = number;
      }
      ++groups[c - 'a'].second;
    }
    vector<int> result(gn, 0);
    for (const auto& [fi, se] : groups) {
      if (fi != -1) result[fi - 1] += se;
    }
    return result;
  }

  // 贪心优化
  vector<int> partitionLabels2(string s) {
    vector<int> endPos(26, 0);
    for (int i = 0; i < s.size(); ++i) endPos[s[i] - 'a'] = i;
    vector<int> result;
    int end = 0;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      end = max(end, endPos[s[i] - 'a']);
      if (i == end) {
        result.emplace_back(end - start + 1);
        start = i + 1;
      }
    }
    return result;
  }



};