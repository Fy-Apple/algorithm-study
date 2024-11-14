//
// Created by apple on 2024/10/27.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool exist2(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty() || word.empty()) return false;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, string& word, const int i, const int j, const int index) {
    if (index == word.size()) return true;
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[index]) return false;

    char c = board[i][j];
    board[i][j] = '0';

    if (dfs(board, word, i, j + 1, index + 1)) return true;
    if (dfs(board, word, i + 1, j, index + 1)) return true;
    if (dfs(board, word, i, j - 1, index + 1)) return true;
    if (dfs(board, word, i - 1, j, index + 1)) return true;
    board[i][j] = c;
    return false;
  }
};

#include <iostream>
using namespace std;

int g_tempA = 4;
const int g_conTempA = 4;
constexpr int g_conexprTempA = 4;

int main(void)
{
  int tempA = 4;
  const int conTempA = 4;
  constexpr int conexprTempA = 4;
  /*1.正常运行，编译通过*/
  const int &conptrA = tempA;
  const int &conptrB = conTempA;
  const int &conptrC = conexprTempA;


  // /*2.有两个问题：一是引用到局部变量，不能再编译器确定；二是conexprPtrB和conexprPtrC应该为constexpr const类型，编译不过*/
  // constexpr int &conexprPtrA = tempA;
  // constexpr int &conexprPtrB = conTempA;
  // constexpr int &conexprPtrC = conexprTempA;
  //
  // /*3.第一个编译通过，后两个不通过，原因是因为conexprPtrE和conexprPtrF应该为constexpr const类型*/
  // constexpr int &conexprPtrD = g_tempA;
  // constexpr int &conexprPtrE = g_conTempA;
  // constexpr int &conexprPtrF = g_conexprTempA;

  /*4.正常运行，编译通过*/
  constexpr const int &conexprConPtrD = g_tempA;
  constexpr const int &conexprConPtrE = g_conTempA;
  constexpr const int &conexprConPtrF = g_conexprTempA;

  cout << conexprConPtrF;

  return 0;
}