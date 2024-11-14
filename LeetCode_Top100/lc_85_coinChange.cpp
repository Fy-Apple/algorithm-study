//
// Created by apple on 2024/10/30.
//
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> f(amount + 1, amount + 1);
    f[0] = 0;
    for (const int& coin : coins) {
      for (int j = coin; j <= amount; ++j) {
          f[j] = min(f[j], f[j - coin] + 1);
      }
    }
    return f[amount] > amount ? -1 : f[amount];
  }
  int coinChange2(vector<int>& coins, int amount) {
    vector<vector<int>> f(coins.size() + 1, vector<int>(amount + 1, amount + 1));
    for (int i = 0; i <= coins.size(); ++i) f[i][0] = 0;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = 1; j <= amount; ++j) {
        f[i][j] = f[i - 1][j];
        if (j >= coins[i - 1]) {
          f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
        }
      }
    }
    return f[coins.size()][amount] > amount ? -1 : f[coins.size()][amount];
  }
  int coinChange3(vector<int>& coins, int amount) {
    vector<vector<int>> f(coins.size() + 1, vector<int>(amount + 1, -1));
    for (int i = 0; i <= coins.size(); ++i) f[i][0] = 0;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = 1; j <= amount; ++j) {
        f[i][j] = f[i - 1][j];
        for (int k = 1; j >= k * coins[i - 1]; ++k) {
          if (f[i - 1] [j - k * coins[i - 1]] >= 0) {
            if (f[i][j] > 0) f[i][j] = min(f[i][j], f[i-1][j- k * coins[i - 1]] + k);
            else f[i][j] = f[i-1][j- k * coins[i - 1]] + k;
          }
        }
      }
    }
    return f[coins.size()][amount];
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 2, 5};
  cout << s.coinChange(test, 11);

  return 0;
}

