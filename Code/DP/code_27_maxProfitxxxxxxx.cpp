//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"

// 限制交易次数为k次，并且包含冷冻期
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    // 第k次交易，持有股票
    vector<int> buy(k + 1, -prices[0]);
    // 第k次卖出，冷却期
    vector<int> sell(k + 1, 0);
    // 第k次卖出，非冷却期
    vector<int> free(k + 1, 0);

    for (const int& price : prices) {
      for (int count = 1; count <= k; ++count) {
        buy[count] = max(buy[count], free[count - 1] - price);
        free[count] = max(free[count], sell[count]);
        sell[count] = max(sell[count], buy[count] + price);
      }
    }
    return max(free[k], sell[k]);
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  // 测试用例 1
  vector<int> test1 = {1, 2, 3, 0, 2}; // 答案：3
  cout << "Test 1: " << s.maxProfit(2, test1) << endl;

  // 测试用例 2
  vector<int> test2 = {5, 4, 3, 2, 1}; // 答案：0
  cout << "Test 2: " << s.maxProfit(2, test2) << endl;

  // 测试用例 3
  vector<int> test3 = {1, 2, 3, 0, 2}; // 答案：3（k 大于交易次数上限，退化）
  cout << "Test 3: " << s.maxProfit(100, test3) << endl;

  // 测试用例 4
  vector<int> test4 = {3, 2, 6, 5, 0, 3}; // 答案：4（只能交易一次）
  cout << "Test 4: " << s.maxProfit(1, test4) << endl;

  // 测试用例 5
  vector<int> test5 = {3, 2, 6, 5, 0, 3}; // 答案：7
  cout << "Test 5: " << s.maxProfit(2, test5) << endl;

  // 测试用例 6
  vector<int> test6 = {}; // 答案：0（空数据）
  cout << "Test 6: " << s.maxProfit(2, test6) << endl;

  // 测试用例 7
  vector<int> test7 = {5}; // 答案：0（单天价格）
  cout << "Test 7: " << s.maxProfit(2, test7) << endl;

  // 测试用例 8
  vector<int> test8 = {1, 2, 3, 4, 5}; // 答案：4（单次交易即可完成）
  cout << "Test 8: " << s.maxProfit(3, test8) << endl;

  return 0;
}
