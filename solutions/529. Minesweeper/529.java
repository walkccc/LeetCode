class Solution {
  public char[][] updateBoard(char[][] board, int[] click) {
    final int i = click[0];
    final int j = click[1];
    if (board[i][j] == 'M') {
      board[i][j] = 'X';
      return board;
    }

    dfs(board, i, j);
    return board;
  }

  private static final int[][] dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  private void dfs(char[][] board, int i, int j) {
    if (i < 0 || i == board.length || j < 0 || j == board[0].length)
      return;
    if (board[i][j] != 'E')
      return;

    final int minesCount = getMinesCount(board, i, j);
    board[i][j] = minesCount == 0 ? 'B' : (char) ('0' + minesCount);

    if (minesCount == 0)
      for (int[] dir : dirs)
        dfs(board, i + dir[0], j + dir[1]);
  }

  private int getMinesCount(char[][] board, int i, int j) {
    int minesCount = 0;
    for (final int[] dir : dirs) {
      final int x = i + dir[0];
      final int y = j + dir[1];
      if (x < 0 || x == board.length || y < 0 || y == board[0].length)
        continue;
      if (board[x][y] == 'M')
        ++minesCount;
    }
    return minesCount;
  }
}
