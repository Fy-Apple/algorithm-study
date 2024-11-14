//
// Created by orange on 11/5/24.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int x = nums[0];
    for (int i = 0;i < nums.size(); ++i) {
      if (nums[i] == x) return x;
      x = nums[i];
    }
    return x;
  }
};

int main(int argc, char *argv[]) {


  return 0;
}


