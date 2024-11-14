//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }
  vector<int> sums(n + 1, 0);
  for (int i = 1; i <= nums.size(); ++i)
    sums[i] = sums[i - 1] + nums[i - 1];
  int left, right;
  while(cin >> left >> right)
    cout << sums[right + 1] - sums[left + 1] + nums[left] << endl;
}