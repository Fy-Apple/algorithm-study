//
// Created by orange on 11/5/24.
//
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (const auto& num : nums) {
      ret ^= num;
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}



