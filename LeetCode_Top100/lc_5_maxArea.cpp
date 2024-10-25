//
// Created by apple on 2024/10/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() == 1) return height[0];
    int left = 0, right = height.size() - 1;
    int maxNum = 0;
    while (left != right) {
     	int currentNum = (abs(right - left)) * min(height[right], height[left]);
			maxNum = max(currentNum, maxNum);
    	if (height[left] < height[right]) ++left;
    	else --right;
    }
    return maxNum;
	}
};

int main(int agrc, char** argv) {
	Solution s;
  vector<int> test = {1,8,6,2,5,4,8,3,7};
	vector<int> test2 = {1,8,6,2,5,4,8,3,7};
	cout << s.maxArea(test2);
	return 0;
}