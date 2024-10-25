//
// Created by apple on 2024/10/14.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        for (string& str: strs) {
            string key = str;;
            std::ranges::sort(key.begin(), key.end());
            strMap[key].emplace_back(str);
        }
        vector<vector<string>> result;
        // c++20
        for (const auto& value: std::views::values(strMap)) {
            result.emplace_back(value);
        }
        return result;
    }
};

int main(int agrc, char** argv) {
    Solution s;
    vector<string> test1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> receive = s.groupAnagrams(test1);

    for (const auto& row : receive) {
        std::cout << "[";
        for (const auto& str : row) {
            std::cout << str << " ";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    return 0;
}