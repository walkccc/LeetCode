class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty())
      return;

    const int m = board.size();
    const int n = board[0].size();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          dfs(board, i, j);

    for (vector<char>& row : board)
      for (char& c : row)
        if (c == '*')
          c = 'O';
        else if (c == 'O')
          c = 'X';
  }

 private:
  // mark 'O' grids that stretch from four sides with '*'
  void dfs(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
      return;
    if (board[i][j] != 'O')
      return;

    board[i][j] = '*';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }
};
