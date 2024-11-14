//
// Created by orange on 11/10/24.
//
#include <vector>
#include <string>
using namespace std;

// 383. 赎金信
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> vec(26, 0);
    for (const auto& c : magazine) ++vec[c - 'a'];
    for (const auto& c : ransomNote) {
      --vec[c - 'a'];
      if (vec[c - 'a'] < 0) return false;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {


  return 0;
}