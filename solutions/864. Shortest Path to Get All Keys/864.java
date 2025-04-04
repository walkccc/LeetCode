class T {
  public int i;
  public int j;
  public int keys; // the keys in the bitmask
  public T(int i, int j, int keys) {
    this.i = i;
    this.j = j;
    this.keys = keys;
  }
}

class Solution {
  public int shortestPathAllKeys(String[] grid) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.length;
    final int n = grid[0].length();
    final int keysCount = getKeysCount(grid);
    final int KEYS = (1 << keysCount) - 1;
    final int[] start = getStart(grid);
    Queue<T> q = new ArrayDeque<>(List.of(new T(start[0], start[1], 0)));
    boolean[][][] seen = new boolean[m][n][KEYS];
    seen[start[0]][start[1]][0] = true;

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().i;
        final int j = q.peek().j;
        final int keys = q.poll().keys;
        for (int[] dir : DIRS) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          final char c = grid[x].charAt(y);
          if (c == '#')
            continue;
          final int newKeys = 'a' <= c && c <= 'f' ? keys | 1 << c - 'a' : keys;
          if (newKeys == KEYS)
            return step;
          if (seen[x][y][newKeys])
            continue;
          if ('A' <= c && c <= 'F' && (newKeys >> c - 'A' & 1) == 0)
            continue;
          q.offer(new T(x, y, newKeys));
          seen[x][y][newKeys] = true;
        }
      }

    return -1;
  }

  private int getKeysCount(String[] grid) {
    int count = 0;
    for (final String s : grid)
      count += (int) s.chars().filter(c -> 'a' <= c && c <= 'f').count();
    return count;
  }

  private int[] getStart(String[] grid) {
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length(); ++j)
        if (grid[i].charAt(j) == '@')
          return new int[] {i, j};
    throw new IllegalArgumentException();
  }
}
