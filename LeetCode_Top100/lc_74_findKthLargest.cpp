//
// Created by apple on 2024/10/29.
//
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int quickSelect(vector<int>& nums, int l, int r, int k) {
    if (l == r) return nums[l];
    int left = l, right = r;
    const int temp = nums[l + (r - l) / 2];
    while (left <= right) {
      while (nums[left] > temp) ++left;
      while (nums[right] < temp) --right;
      if (left <= right)
        swap(nums[left++], nums[right--]);
    }
    if (k <= right) return quickSelect(nums, l, right, k);
    if (k >= left) return quickSelect(nums, left, r, k);
    return nums[k];
  }
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, static_cast<int>(nums.size() - 1), k - 1);
  }
  int findKthLargest1(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> topKq;
    for (int i = 0; i < k; ++i) topKq.push(nums[i]);
    for (int i = k; i < nums.size(); ++i) {
      if (nums[i] > topKq.top()) {
        topKq.pop();
        topKq.push(nums[i]);
      }
    }
    return topKq.top();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {3,2,1,5,6,4};
  cout << s.findKthLargest(test, 2);
  return 0;
}
