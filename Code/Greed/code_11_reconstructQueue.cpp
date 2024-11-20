//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

#include <algorithm>
// 406. 根据身高重建队列
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> result(people.size(), vector<int>());
    sort(people.begin(), people.end());
    for (const auto& p : people) {
      int num = p[1];
      int index = 0;
      while (num) {
        if (result[index].empty() || result[index][0] >= p[0]) {
          --num;
        }
        ++index;
      }
      while (index < result.size() && !result[index].empty()) {
        ++index;
      }
      if (index < result.size()) result[index] = p;
    }
    return result;
  }
};

// [5, 0][7, 0][5, 2][6, 1] [4, 4] [7, 1]