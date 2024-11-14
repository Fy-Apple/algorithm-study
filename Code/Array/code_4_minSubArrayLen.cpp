//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen2(int target, vector<int>& nums) {
    int minLen = nums.size() + 1;
     for (int i = 0; i < nums.size(); ++i) {
       int cur = 0, sum = 0;
       while (i + cur < nums.size() && sum < target) {
         sum += nums[i + cur];
         ++cur;
       }
       if (sum >= target) minLen = min(minLen, cur);
       if (i + cur == nums.size()) break;
     }

    return minLen > nums.size() ? 0 : minLen;
  }
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0, sum = 0;
    int minLen = nums.size() + 1;
    for (; right < nums.size(); ++right) {
      sum += nums[right];
      while (sum >= target) {
        minLen = min(minLen, right - left + 1);
        sum -= nums[left];
        ++left;
      }
    }
    return minLen == nums.size() + 1 ? 0 : minLen;
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {2, 3, 1, 2, 4, 3};
  cout << s.minSubArrayLen(7, test);

  return 0;
}
