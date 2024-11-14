//
// Created by apple on 2024/10/26.
//
#include <deque>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();
    queue<pair<int, int>> pos;
    bool orange = false;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
         if (grid[i][j] == 1) {
           orange = true;
         }
        if (grid[i][j] == 2) {
          pos.emplace(i, j);
        }
      }
    }
    if (!orange) return 0;
    int minutes = 0;
    while (!pos.empty()){
      int size = pos.size();
      for (int index = 0; index < size; ++index) {
        auto [i, j] = pos.front();
        if (i + 1 < row && grid[i + 1][j] == 1) {
          grid[i + 1][j] = 2;
          pos.emplace(i + 1, j);
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
          grid[i - 1][j] = 2;
          pos.emplace(i - 1, j);
        }
        if (j + 1 < col && grid[i][j + 1] == 1) {
          grid[i][j + 1] = 2;
          pos.emplace(i, j + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
          grid[i][j - 1] = 2;
          pos.emplace(i, j - 1);
        }
        pos.pop();
      }
      ++minutes;
    }
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return minutes - 1;
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> test =
    {
      {2, 1, 1},
      {1, 1, 1},
      {0, 1, 2}
    };
  cout << s.orangesRotting(test) << endl;
  for (const auto& v : test) {
    for (const auto num : v) {
      cout << num << " ";
    }
    cout << endl;
  }
}
