//
// Created by orange on 11/14/24.
//
#include "code_0_header.h"

// 37. 解数独
class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    // 存储每个位置可用的数字，和N皇后存储列，左右对角线类似
    vector<vector<bool>> row(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> blk(9, vector<bool>(9, false));
    // 初始化不可用的数字
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          const int val = board[i][j] - '1';
          // 行 / 3 * 3 + 列 / 3可将9个块映射到~8
          row[i][val] = col[j][val] = blk[i / 3 * 3 + j / 3][val] = true;
        }
      }
    }
    dfs(board, row, col, blk, 0, 0);
  }

  bool dfs(vector<vector<char>>& board, vector<vector<bool>>& row,
    vector<vector<bool>>& col, vector<vector<bool>>& blk,
    const int r, const int c) {
    // 行号为9表示全部填充完毕找到答案了(0~8)
    if (r == 9) return true;
    // 列号为9 说明要换新的行填充
    if (c == 9) return dfs(board, row, col, blk, r + 1, 0);

    // 跳过非'.' 即已填充数字的格子
    if (board[r][c] != '.') return dfs(board, row, col, blk, r, c + 1);

    // 依次遍历当前单元格所有可以使用的数字，进行回溯
    for (int num = 0; num < 9; ++num) {
      // 跳过不可用数字
      if (row[r][num] || col[c][num] || blk[r / 3 * 3 + c / 3][num]) continue;
      row[r][num] = col[c][num] = blk[r / 3 * 3 + c / 3][num] = true;
      board[r][c] = '1' + num;
      if (dfs(board, row, col, blk, r, c + 1)) return true;
      board[r][c] = '.';
      row[r][num] = col[c][num] = blk[r / 3 * 3 + c / 3][num] = false;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char>> board = {
      {'5','3','.','.','7','.','.','.','.'},
       {'6','.','.','1','9','5','.','.','.'},
       {'.','9','8','.','.','.','.','6','.'},
       {'8','.','.','.','6','.','.','.','3'},
       {'4','.','.','8','.','3','.','.','1'},
       {'7','.','.','.','2','.','.','.','6'},
       {'.','6','.','.','.','.','2','8','.'},
       {'.','.','.','4','1','9','.','.','5'},
       {'.','.','.','.','8','.','.','7','9'}
  };
  s.solveSudoku(board);
  for (const auto& v : board) {
    for (const auto& c : v) {
      cout << c << ", ";
    }
    cout << endl;
  }

  return 0;
}

/**
 * [0, 0]   [0, 1]    [0, 2] （0, 0） (0, 1) (0, 2)
 * [1, 0]   [1, 1]    [1, 2]  (1, 0) (1, 1) (1, 2)
 * [2, 0]   [2, 1]    [2, 2]  (2, 0) (2, 1) (2, 2)
 *                            [3, 3]    [3, 4]    [3, 5] (1, 1)
 *                            [4, 3]
 *                            [5, 3]
 */