//
// Created by apple on 2024/10/15.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() == 1) cout << "[" << nums[0] << "]" << endl;

       	for (int i = 0, j = 1; j < nums.size();) {
			if (nums[i] == 0 && nums[j] != 0) {
				const int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}else if (nums[i] == 0 && nums[j] == 0) {
				++j;
			}else {
				++i;
				if ( i == j) ++j;
			}
       	}

		cout << "[";
		for (auto it = 0; it < nums.size(); ++it) {
			cout << nums[it];
			if (it != nums.size() - 1) cout << ",";
		}
		cout << "]";
	}
};


int main(int argc, char** argv) {
	Solution s;
    vector<int> nums = {0,1,0,3,12};
	s.moveZeroes(nums);

	return 0;
}