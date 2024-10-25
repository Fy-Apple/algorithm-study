//
// Created by apple on 2024/10/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    if (nums.empty()) return  result;
    if (nums.size()  == 1) return nums;

    vector<int> prev(nums.size());
    prev[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      prev[i] = prev[i - 1] * nums[i - 1];
    }

    vector<int> next(nums.size());
    next[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      next[i] = next[ i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); ++i) {
      result.emplace_back(prev[i] * next[i]);
    }

    return result;
  }
};

int main(int argc, char** argv) {
  Solution s;

  vector<int> test = {1,2,3,4};
  cout << "[";
  for(const auto& v: s.productExceptSelf(test)) {
    cout << v << ", ";
  }
  cout << "], ";

  return 0;
}