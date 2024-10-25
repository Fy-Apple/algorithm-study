//
// Created by apple on 2024/10/14.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    // 超时，超内存
    int longestConsecutive_prev(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxNum = -100000000;
        int minNum = 100000000;
        for (const auto& i: nums) {
            if (i > maxNum) maxNum = i;
            if (i < minNum) minNum = i;
        }
        vector<bool> array(maxNum - minNum + 1, false);
        for (const auto& i: nums)
            array[i - minNum] = true;

        int maxLength = 1;
        int now = 0;
        for (auto flag: array) {
            if (flag){
                 now = now + 1;
            }else{
                if (now > maxLength) maxLength = now;
                now = 0;
            }
        }
        if (now > maxLength) maxLength = now;
        return maxLength;
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 1;
        for(const auto num: nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentLength = 1;
                int currentNum = num;

                while (numSet.find(++currentNum) != numSet.end()) {
                    ++ currentLength;
                }
                maxLength = max(maxLength, currentLength);
            }
        }
        return maxLength;
    }
};

int main(int agrc, char** argv) {
    Solution s;
    vector<int> test1 = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(test1);

    return 0;
}