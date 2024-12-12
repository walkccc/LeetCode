class Solution {
  public void solve(char[][] board) {
    if (board.length == 0)
      return;

    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = board.length;
    final int n = board[0].length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (board[i][j] == 'O') {
            q.offer(new Pair<>(i, j));
            board[i][j] = '*';
          }

    // Mark the grids that stretch from the four sides with '*'.
    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (board[x][y] != 'O')
          continue;
        q.offer(new Pair<>(x, y));
        board[x][y] = '*';
      }
    }

    for (char[] row : board)
      for (int i = 0; i < row.length; ++i)
        if (row[i] == '*')
          row[i] = 'O';
        else if (row[i] == 'O')
          row[i] = 'X';
  }
}
