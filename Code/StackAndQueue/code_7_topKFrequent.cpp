//
// Created by orange on 11/11/24.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 347.前 K 个高频元素
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequentMap;
    for (const auto& num : nums) {
      ++frequentMap[num];
    }
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
      return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> smallHeap(cmp);
    auto it = frequentMap.begin();
    for (int i = 0; i < k; ++i) {
      smallHeap.emplace(*it);
      ++it;
    }
    for (; it != frequentMap.end(); ++it) {
      if (it->second > smallHeap.top().second) {
        smallHeap.pop();
        smallHeap.emplace(*it);
      }
    }
    vector<int> result;
    while (!smallHeap.empty()) {
      result.push_back(smallHeap.top().first);
      smallHeap.pop();
    }
    return result;
  }
};