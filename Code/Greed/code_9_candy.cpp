//
// Created by Orange on 2024/11/19.
//
#include <numeric>

#include "code_0_headers.h"
//135. 分发糖果
class Solution {
public:
  int candy(vector<int>& ratings) {
    vector<int> result(1, 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        result.emplace_back(result.back() + 1);
      }
      else if (ratings[i] < ratings[i - 1]){
        if (result.back() == 1) {
          int j = static_cast<int>(result.size()) - 1;
          ++result[j];
          while (j >= 1 && ratings[j] != ratings[j - 1] && result[j] == result[j - 1]) {
            --j;
            ++result[j];
          }
        }
        result.emplace_back(1);
      }
      else {
        result.emplace_back(1);
      }
    }
    int sum = 0;
    for (const auto& num : result) sum += num;
    return sum;
  }

  int candy2(vector<int>& ratings) {
    vector<int> result(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) result[i] = result[i - 1] + 1;
    }
    for (int i = static_cast<int>(ratings.size()) - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) result[i] = max(result[i], result[i + 1] + 1);
    }
    return accumulate(result.begin(), result.end(), 0);
  }


};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1,2,87,87,87,2,1};
  // 1 2 3 1 3 2 1
  cout << s.candy2(test);

  return 0;
}
