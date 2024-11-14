//
// Created by orange on 11/14/24.
//
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

#include "code_0_header.h"


// 332. 重新安排行程
class Solution {
private:
  unordered_map<string, map<string, int>> destMap;
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> result;
    for (const auto& ticket : tickets) {
      ++destMap[ticket[0]][ticket[1]];
    }
    result.emplace_back("JFK");
    dfs(result, tickets);
    return result;
  }

  bool dfs(vector<string>& result, vector<vector<string>>& tickets) {
    if (result.size() == tickets.size() + 1) {
      return true;
    }
    for (auto& dest : destMap[result[result.size() - 1]]) {
      if (dest.second == 0) continue;
      result.emplace_back(dest.first);
      --dest.second;
      if (dfs(result, tickets)) return true;
      ++dest.second;
      result.pop_back();
    }
    return false;
  }

  // 查找欧拉通路
  /**
   *
   * 1.从起始节点出发进行深度优先遍历
   * 2.遍历每个节点的所有边直到遍历完所有节点
   * 3.对于每个节点，遍历了所有边以后才将节点入栈
   * 4.得到的结果就是欧拉通路的逆序输出
   */
  vector<string> findItinerary2(vector<vector<string>>& tickets) {
    vector<string> result;
    unordered_map<string, map<string, int>> endpoints;
    for (const auto& ticket : tickets) {
      ++endpoints[ticket[0]][ticket[1]];
    }
    olDFS(result, tickets, endpoints, "JFK");
    reverse(result.begin(), result.end());
    return result;
  }

  void olDFS(vector<string>& result, vector<vector<string>>& tickets,
    unordered_map<string, map<string, int>>& endpoints, string place) {
    for (auto& [dest, num] : endpoints[place]) {
      if (num > 0) {
        --num;
        olDFS(result, tickets, endpoints, dest);
      }
    }
    result.emplace_back(std::move(place));
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
  for (const string& d : s.findItinerary(tickets)) {
    cout << d << ", ";
  }
  return 0;
}

