//
// Created by apple on 2024/10/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b){return a[0] < b[0];});
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > intervals[i - 1][1]) {
        result.emplace_back(intervals[i - 1]);
      }else {
        intervals[i][0] = intervals[i - 1][0];
        intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
      }
    }
    result.emplace_back(intervals[intervals.size() - 1]);
    return result;
  }
};


int main(int argc, char** argv) {
  Solution s;
  vector<vector<int>> test = {{1,3},{2,6},{8,10},{15,18}};
  for(const auto& v: s.merge(test)) {
    cout << "[";
    for (const auto& num : v) {
      cout << num << ", ";
    }
    cout << "], ";
  }


  return 0;
}