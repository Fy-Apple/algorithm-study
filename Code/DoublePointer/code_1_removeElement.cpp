//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <vector>
using namespace std;

//
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int slow = 0, fast = 0;
    for (; fast < nums.size(); ++fast) {
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
    }
    for (; slow < fast; ++slow) {
      nums.pop_back();
    }
    return nums.size();
  }
};

int main(int agrc, char* argv[]) {

  return 0;
}