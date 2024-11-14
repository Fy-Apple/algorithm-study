//
// Created by apple on 2024/10/28.
//
#include <iostream>
#include <vector>
using namespace std;


/*
 * l1          r1
 *  ↓           ↓
 * [1, 3, [5], 7]
 *
 * l2          r2
 *  ↓          ↓
 * [2, [4], 6, 8]
 *
 * l
 *
 *
 *
 *
 *
 * */


class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int totalNums = nums1.size() + nums2.size();
    auto minK = [&nums1, &nums2](int k)->int {
      int left1 = 0, left2 = 0;
      while (true) {
        if (left1 == nums1.size()) return nums2[left2 + k - 1];
        if (left2 == nums2.size()) return nums1[left1 + k - 1];
        if (k == 1) return min(nums1[left1], nums2[left2]);
        const int idx1 = min(left1 + k / 2 - 1, static_cast<int>(nums1.size() - 1));
        const int idx2 = min(left2 + k / 2 - 1, static_cast<int>(nums2.size() - 1));
        if (nums1[idx1] <= nums2[idx2]) {
          k -= (idx1 - left1 + 1);
          left1 = idx1 + 1;
        }else {
          k -= (idx2 - left2 + 1);
          left2 = idx2 + 1;
        }
      }
    };
    const int midIndex = (totalNums + 1) / 2;
    if (totalNums % 2 == 1) return minK(midIndex);
    return (minK(midIndex) + minK(midIndex + 1)) / 2.0;
  }
};

int main (int argc, char* argv[]) {
  Solution s;
  vector<int> test1 = {1, 3, 5, 7};
  vector<int> test2 = {2, 4, 6, 8};

  cout << s.findMedianSortedArrays(test1, test2);

  return 0;
}