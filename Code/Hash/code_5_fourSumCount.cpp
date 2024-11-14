//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> sums;
    for (const auto& num1 : nums1) {
      for (const auto& num2 : nums2) {
        ++sums[num1 + num2];
      }
    }
    int result = 0;
    for (const auto& num3 : nums3) {
      for (const auto& num4 : nums4) {
       if (sums.count(-num3 - num4)) result += sums[-num3 - num4];
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> test1 = {1, 2};
  vector<int> test2 = {-2, -1};
  vector<int> test3 = {-1, 2};
  vector<int> test4 = {0, 2};
  cout << s.fourSumCount(test1, test2, test3, test4);

  return 0;
}