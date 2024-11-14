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
  int majorityElement(vector<int>& nums) {
    int num = nums[0], count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (num == nums[i]) ++count;
      else if (count == 1) num = nums[i];
      else --count;
    }
    return num;
  }
};

int main(int argc, char *argv[]) {


  return 0;
}
