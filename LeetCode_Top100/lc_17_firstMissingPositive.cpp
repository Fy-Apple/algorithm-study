//
// Created by apple on 2024/10/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // 最小数必定落在1~N+1上，  正好1~N的数组范围，利用原始数组优化空间复杂度
  int firstMissingPositive2(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 1) {
        nums[i] = static_cast<int>(nums.size()) + 1;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (abs(nums[i]) >= 1 && abs(nums[i]) <= nums.size()) {
        if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) return i + 1;
    }
    return  static_cast<int>(nums.size() + 1);
  }

  // 交换数字
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
        const int temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
        cout << "i: " << i << ", nums[i]: " << nums[i] <<  ", nums[nums[i] - 1]: " << nums[nums[i] - 1] << endl;
      }
    }
    for (const auto& num : nums) {
      cout << num;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return  i + 1;
      }
    }
    return static_cast<int>(nums.size()) + 1;
  }
};

int main(int argc, char** argv) {
  Solution s;

  vector<int> test = {3, 4, -1, 1};
  cout << s.firstMissingPositive(test);

  return 0;
}