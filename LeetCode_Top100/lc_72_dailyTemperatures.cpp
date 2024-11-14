//
// Created by apple on 2024/10/29.
//
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> invertedS;
    vector<int> result(temperatures.size(), 0);
    for (int i = static_cast<int>(temperatures.size()) - 1; i >= 0; --i) {
      while (!invertedS.empty() && temperatures[i] >= invertedS.top().first) {
        invertedS.pop();
      }
      if (!invertedS.empty()) result[i] = invertedS.top().second - i;
      invertedS.emplace(temperatures[i], i);
    }
    return result;
  }
};

int main(int argc, char* argv) {
  Solution s;
  vector<int> test = {73,74,75,71,69,72,76,73};
  for (auto num : s.dailyTemperatures(test)) {
    cout << num << ", ";
  }
  return 0;
}