//
// Created by orange on 11/10/24.
//
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> sums;
    while(true) {
       if (n == 1) return true;
       if (sums.count(n)) return false;
       sums.emplace(n);
       int newN = 0;
       while (n) {
         newN += (n % 10) * (n % 10);
         n /= 10;
       }
       n = newN;
     }
  }
};


int main(int agrc, char* agrv[]) {


  return 0;
}