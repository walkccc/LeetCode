class Solution {
  public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
    final int[][] dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int k = 0; k < 8; ++k) {
      final int dx = dirs[k][0];
      final int dy = dirs[k][1];
      int cellsCount = 2;
      int i = rMove + dx;
      int j = cMove + dy;
      while (0 <= i && i < 8 && 0 <= j && j < 8) {
        // There are no free cells in between.
        if (board[i][j] == '.')
          break;
        // Need >= 3 cells.
        if (cellsCount == 2 && board[i][j] == color)
          break;
        // >= 3 cells.
        if (board[i][j] == color)
          return true;
        i += dx;
        j += dy;
        ++cellsCount;
      }
    }

    return false;
  }
}
