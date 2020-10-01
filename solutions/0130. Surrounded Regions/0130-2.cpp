class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty()) return;

    const int m = board.size();
    const int n = board[0].size();

    // mark grids that stretch from four sides with '*'
    function<void(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (board[i][j] != 'O') return;

      board[i][j] = '*';
      dfs(i + 1, j);
      dfs(i - 1, j);
      dfs(i, j + 1);
      dfs(i, j - 1);
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if ((i == 0 || i == m - 1) || (j == 0 || j == n - 1))
          dfs(i, j);

    for (vector<char>& row : board)
      for (char& c : row)
        if (c == '*')
          c = 'O';
        else if (c == 'O')
          c = 'X';
  }
};
