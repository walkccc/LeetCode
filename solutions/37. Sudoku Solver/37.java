class Solution {
  public void solveSudoku(char[][] board) {
    dfs(board, 0);
  }

  private boolean dfs(char[][] board, int s) {
    if (s == 81)
      return true;

    final int i = s / 9;
    final int j = s % 9;

    if (board[i][j] != '.')
      return dfs(board, s + 1);

    for (char c = '1'; c <= '9'; ++c)
      if (isValid(board, i, j, c)) {
        board[i][j] = c;
        if (dfs(board, s + 1))
          return true;
        board[i][j] = '.';
      }

    return false;
  }

  private boolean isValid(char[][] board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i)
      if (board[i][col] == c || board[row][i] == c ||
          board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        return false;
    return true;
  }
}
