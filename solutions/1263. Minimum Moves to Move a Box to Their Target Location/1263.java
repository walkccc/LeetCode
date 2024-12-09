class Solution {
  public int minPushBox(char[][] grid) {
    record T(int boxX, int boxY, int playerX, int playerY) {}
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

    Queue<T> q = new ArrayDeque<>(List.of(new T(box[0], box[1], player[0], player[1])));
    boolean[][][][] seen = new boolean[m][n][m][n];
    seen[box[0]][box[1]][player[0]][player[1]] = true;

    for (int step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int boxX = q.peek().boxX;
        final int boxY = q.peek().boxY;
        final int playerX = q.peek().playerX;
        final int playerY = q.poll().playerY;
        if (boxX == target[0] && boxY == target[1])
          return step;
        for (int k = 0; k < 4; ++k) {
          final int nextBoxX = boxX + dirs[k][0];
          final int nextBoxY = boxY + dirs[k][1];
          if (isInvalid(grid, nextBoxX, nextBoxY))
            continue;
          if (seen[nextBoxX][nextBoxY][boxX][boxY])
            continue;
          final int fromX = boxX + dirs[(k + 2) % 4][0];
          final int fromY = boxY + dirs[(k + 2) % 4][1];
          if (isInvalid(grid, fromX, fromY))
            continue;
          if (canGoTo(grid, playerX, playerY, fromX, fromY, boxX, boxY)) {
            seen[nextBoxX][nextBoxY][boxX][boxY] = true;
            q.offer(new T(nextBoxX, nextBoxY, boxX, boxY));
          }
        }
      }

    return -1;
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // Returns true if (playerX, playerY) can go to (fromX, fromY).
  private boolean canGoTo(char[][] grid, int playerX, int playerY, int fromX, int fromY, int boxX,
                          int boxY) {
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(playerX, playerY)));
    boolean[][] seen = new boolean[grid.length][grid[0].length];
    seen[playerX][playerY] = true;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      if (i == fromX && j == fromY)
        return true;
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
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
