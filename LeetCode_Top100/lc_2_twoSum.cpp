//
// Created by apple on 2024/10/14.
//
#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, uint16_t> numsMap;

        for(auto i = 0; i < nums.size(); ++i) {
            if(numsMap.find(target - nums[i]) != numsMap.end()) {
                return {numsMap.find(target - nums[i])->second, i};
            }
            numsMap.emplace(nums[i], i);
        }
        return {0, 0};
    }
};


int main(int agrc, char** argv) {
    Solution s;
    vector<int> test1 = {2, 7, 11, 15};
    vector<int> test2 = {3, 2, 4};
    vector<int> test3 = {3, 3};

    vector<int> receive = s.twoSum(test1, 9);
    cout << receive[0] << ", " << receive[1] << endl;

    vector<int> receive2 = s.twoSum(test2, 6);
    cout << receive2[0] << ", " << receive2[1] << endl;

    vector<int> receive3 = s.twoSum(test3, 6);
    cout << receive3[0] << ", " << receive3[1] << endl;
    return 0;
}