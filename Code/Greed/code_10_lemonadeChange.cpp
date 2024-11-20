//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"
// 860.柠檬水找零
class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> moneys = {{5, 0}, {10, 0}};
    for (const auto& value : bills) {
      if (value == 5) ++moneys[5];
      else if (value == 10)
      {
        if (moneys[5] == 0) return false;
        --moneys[5];
        ++moneys[10];
      }
      else
      {
        if (moneys[10] >= 1 && moneys[5] >= 1)
        {
          --moneys[10];
          --moneys[5];
        }
        else if (moneys[5] >= 3)
        {
          moneys[5] -= 3;
        }
        else
        {
          return false;
        }
      }
    }
    return true;
  }
};