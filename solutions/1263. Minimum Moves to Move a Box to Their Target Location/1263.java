class Solution {
  public int minPushBox(char[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[] box = {-1, -1};
    int[] player = {-1, -1};
    int[] target = {-1, -1};

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 'B')
          box = new int[] {i, j};
        else if (grid[i][j] == 'S')
          player = new int[] {i, j};
        else if (grid[i][j] == 'T')
          target = new int[] {i, j};

    int ans = 0;
    // (boxX, boxY, playerX, playerY)
    Queue<int[]> q =
        new ArrayDeque<>(Arrays.asList(new int[] {box[0], box[1], player[0], player[1]}));
    boolean[][][][] seen = new boolean[m][n][m][n];
    seen[box[0]][box[1]][player[0]][player[1]] = true;

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int boxX = q.peek()[0];
        final int boxY = q.peek()[1];
        final int playerX = q.peek()[2];
        final int playerY = q.poll()[3];
        if (boxX == target[0] && boxY == target[1])
          return ans;
        for (int k = 0; k < 4; ++k) {
          final int nextBoxX = boxX + dirs[k];
          final int nextBoxY = boxY + dirs[k + 1];
          if (isInvalid(grid, nextBoxX, nextBoxY))
            continue;
          if (seen[nextBoxX][nextBoxY][boxX][boxY])
            continue;
          final int fromX = boxX + dirs[(k + 2) % 4];
          final int fromY = boxY + dirs[(k + 3) % 4];
          if (isInvalid(grid, fromX, fromY))
            continue;
          if (canGoTo(grid, playerX, playerY, fromX, fromY, boxX, boxY)) {
            seen[nextBoxX][nextBoxY][boxX][boxY] = true;
            q.offer(new int[] {nextBoxX, nextBoxY, boxX, boxY});
          }
        }
      }
      ++ans;
    }

    return -1;
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};

  // true if (playerX, playerY) can go to (fromX, fromY)
  private boolean canGoTo(char[][] grid, int playerX, int playerY, int fromX, int fromY, int boxX,
                          int boxY) {
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(Arrays.asList(new Pair<>(playerX, playerY)));
    boolean[][] seen = new boolean[grid.length][grid[0].length];
    seen[playerX][playerY] = true;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      if (i == fromX && j == fromY)
        return true;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (isInvalid(grid, x, y))
          continue;
        if (seen[x][y])
          continue;
        if (x == boxX && y == boxY)
          continue;
        q.offer(new Pair<>(x, y));
        seen[x][y] = true;
      }
    }

    return false;
  }

  private boolean isInvalid(char[][] grid, int playerX, int playerY) {
    return playerX < 0 || playerX == grid.length || playerY < 0 || playerY == grid[0].length ||
        grid[playerX][playerY] == '#';
  }
}
