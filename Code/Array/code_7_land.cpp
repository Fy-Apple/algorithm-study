//
// Created by orange on 11/10/24.
//
#include <iostream>
#include <vector>
using namespace std;

//  开发商购买土地   非lc
int main(int argc, char* argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));
  vector<int> sumRow(n, 0), sumCol(m, 0);
  for (auto& v : nums) {
    for (auto& num : v) {
      cin >> num;
    }
  }


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      sumRow[i] += nums[i][j];
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      sumCol[j] += nums[i][j];
    }
  }

  vector<pair<int, int>> prefixRow(n + 1, pair<int, int>(0, 0));
  for (int i = 1; i <= n; ++i) {
    prefixRow[i].first = prefixRow[i - 1].first + sumRow[i - 1];
  }
  for (int i = n - 1; i >= 1; --i) {
    prefixRow[i].second = prefixRow[i + 1].second + sumRow[i];
  }

  vector<pair<int, int>> prefixCol(m + 1, pair<int, int>(0, 0));
  for (int j = 1; j <= m; ++j) {
    prefixCol[j].first = prefixCol[j - 1].first + sumCol[j - 1];
  }
  for (int j = m - 1; j >= 1; --j) {
    prefixCol[j].second = prefixCol[j + 1].second + sumCol[j];
  }


  int minDist = abs(prefixRow[1].first - prefixRow[1].second);
  for (int i = 1; i <= n; ++i) {
    //cout << "[" << prefixRow[i].first << ", " << prefixRow[i].second << "], ";
    minDist = min(minDist, abs(prefixRow[i].first - prefixRow[i].second));
  }
  //cout << endl;
  for (int j = 1; j <= m; ++j) {
    //cout << "[" << prefixCol[j].first << ", " << prefixCol[j].second << "], ";
    minDist = min(minDist, abs(prefixCol[j].first - prefixCol[j].second));
  }
  //cout << endl;
  cout << minDist;
}

