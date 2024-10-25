//
// Created by apple on 2024/10/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    vector<int> result(nums.size());
    k = k % nums.size();
    for (int i = 0; i < nums.size() - k; ++i) {
      result[ i + k] = nums[i];
    }
    for (int i = nums.size() - k; i <  nums.size(); ++i) {
      result[ i - nums.size() + k] = nums[i];
    }
    nums.assign(result.begin(), result.end());
  }
};

int main(int argc, char** argv) {
  Solution s;

  vector<int> test = {1,2,3,4,5,6,7};
  s.rotate(test, 3);
  cout << "[";
  for(const auto& v: test) {
      cout << v << ", ";
  }
  cout << "], ";

  return 0;
}