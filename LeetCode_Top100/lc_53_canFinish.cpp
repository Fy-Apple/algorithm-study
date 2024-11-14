//
// Created by apple on 2024/10/26.
//
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    vector<int> inDegreeVec(numCourses, 0);
    for (const auto& edge: prerequisites) {
      graph[edge[1]].emplace_back(edge[0]);
      ++inDegreeVec[edge[0]];
    }
    stack<int> eleStack;
    for (int i = 0; i < numCourses; ++i) {
      if (inDegreeVec[i] == 0) eleStack.push(i);
    }
    int courseNum = 0;
    while (!eleStack.empty()) {
      int course = eleStack.top();
      eleStack.pop();
      ++courseNum;

      for (const auto& next : graph[course]) {
        if (--inDegreeVec[next] == 0) eleStack.push(next);
      }
    }
    return courseNum == numCourses;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int test1 = 0;
  vector<vector<int>> test2 = {};
  cout << s.canFinish(test1, test2) << endl;



}
