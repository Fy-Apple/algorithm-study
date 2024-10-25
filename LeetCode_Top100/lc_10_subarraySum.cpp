//
// Created by apple on 2024/10/18.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
  int subarraySum1(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for(int j = i; j < nums.size(); ++j) {
        if ((sum+=nums[j]) == k)
          ++count;
      }
    }
    return count;
  }

  //
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    unordered_map<int, int> numMap;
    numMap[0] = 1;// 为了单独数组=k时可以+1
    int prev = 0;
    for (const auto& num : nums) {
      prev += num;
      if (numMap.find(prev - k) != numMap.end()) count += numMap[prev-k];
      ++numMap[prev];
    }
    return count;
  }
};


int main(int argc, char** argv) {
  Solution s;
  vector<int> test({1,2,3});
  cout << s.subarraySum(test, 3);


  return 0;
}