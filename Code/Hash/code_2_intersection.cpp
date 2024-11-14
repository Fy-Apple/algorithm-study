//
// Created by orange on 11/10/24.
//
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> result;
    unordered_set<int> numSet(nums1.begin(), nums1.end());
    for (const auto& num: nums2) {
      if (numSet.count(num)) result.emplace(num);
    }
    return {result.begin(), result.end()};
  }
};


int main(int agrc, char* argv[]) {

  return 0;
}
