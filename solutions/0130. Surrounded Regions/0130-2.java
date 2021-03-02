class Solution {
  public void solve(char[][] board) {
    if (board.length == 0)
      return;

    final int m = board.length;
    final int n = board[0].length;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          dfs(board, i, j);

    for (char[] row : board)
      for (int i = 0; i < row.length; ++i)
        if (row[i] == '*')
          row[i] = 'O';
        else if (row[i] == 'O')
          row[i] = 'X';
  }

  // mark 'O' grids that stretch from four sides with '*'
  private void dfs(char[][] board, int i, int j) {
    if (i < 0 || i == board.length || j < 0 || j == board[0].length)
      return;
    if (board[i][j] != 'O')
      return;

    board[i][j] = '*';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }
}
