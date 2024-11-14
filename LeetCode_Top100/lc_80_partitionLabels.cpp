//
// Created by apple on 2024/10/30.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> endPos(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      endPos[s[i] - 'a'] = i;
    }
    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
      end = max(end, endPos[s[i] - 'a']);
      if (i == end) {
        result.emplace_back(end - start + 1);
        start = i + 1;
      }
    }
    return result;
  }
  vector<int> partitionLabels2(string s) {
    int index = 0;
    vector<int> groups(26, 0);
    vector<int> nums;
    for (const auto& c : s) {
      if (groups[c - 'a'] == 0) {
        nums.emplace_back(1);
        groups[c - 'a'] = ++index;
        cout << "First-> [" << c << "], " << groups[c - 'a'] << nums[index - 1] << endl;
      }else {
        cout << "Repeat-> [" << c << "], " << groups[c - 'a'] << endl;
        const int left = groups[c - 'a'];
        for (auto& groupNum : groups) {
          if (groupNum > left) {
            nums[left - 1] += nums[groupNum - 1];
            nums[groupNum - 1] = 0;
            groupNum = left;
          }
        }
        for (auto it = nums.begin(); it != nums.end();) {
          if (*it == 0) {
            it = nums.erase(it);
          }else {
            ++it;
          }
        }
        index = left;
        ++nums[index - 1];
      }
    }
    return nums;
  }
};

int main(int argc, char *argv[]) {
  Solution s;//hijhklij
  vector<int> result = s.partitionLabels("ababcbacadefegdehijhklij");
  cout << endl << "---------------------" << endl;
  for (const auto& num : result) {
    cout << num << ", " ;
  }
  return 0;
}
