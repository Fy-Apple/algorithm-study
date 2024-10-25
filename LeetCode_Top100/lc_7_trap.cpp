//
// Created by apple on 2024/10/16.
//
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int trap(vector<int>& height) {
    vector<int> lMax(height.size(),0);
    lMax[0] = height[0];
    for (int i = 1; i < height.size(); ++i)
      lMax[i] = max(height[i], lMax[i-1]);

    vector<int> rMax(height.size(),0);
    rMax[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; --i)
      rMax[i] = max(height[i], rMax[i+1]);

    int waterNum = 0;
    for (int i = 0; i < height.size(); ++i) {
      cout << "(" << lMax[i] << "," << rMax[i] << ") - " << height[i] << endl;
      waterNum += min(lMax[i], rMax[i]) - height[i];
    }

    return waterNum;
  }
  int trap2(vector<int>& height) {
    if (height.size() <= 2) return 0;

    stack<int> numStack;
    int waterNum = 0;


    for (int index = 0; index < height.size(); ++index) {
      while (!numStack.empty() && height[index] > height[numStack.top()]) {
        int btm = numStack.top();
        numStack.pop();
        if (numStack.empty()) break;
        int left = numStack.top();
        waterNum += (index - left - 1) * (min(height[left], height[index]) - height[btm]);
      }
      numStack.push(index);
    }
    return waterNum;
  }
};

int main(int agrc, char** argv) {
  Solution s;
  vector<int> test({0,1,0,2,1,0,1,3,2,1,2,1});
  cout << s.trap(test);
  return 0;
}