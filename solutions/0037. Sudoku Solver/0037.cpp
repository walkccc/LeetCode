class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    function<bool(int)> dfs = [&](int s) {
      if (s == 81) return true;

      const int i = s / 9;
      const int j = s % 9;

      if (board[i][j] != '.')
        return dfs(s + 1);

      for (char c = '1'; c <= '9'; ++c)
        if (isValid(board, i, j, c)) {
          board[i][j] = c;
          if (dfs(s + 1))
            return true;
          board[i][j] = '.';
        }

      return false;
    };

    dfs(0);
  }

 private:
  bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i)
      if (board[i][col] == c || board[row][i] == c ||
          board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        return false;
    return true;
  }
};