class Solution {
  public int maxStudents(char[][] seats) {
    int studentsCount = 0;

    for (char[] seat : seats)
      for (final char s : seat)
        if (s == '.')
          ++studentsCount;

    return studentsCount - hungarian(seats);
  }

  private static final int[][] dirs = {{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}};

  private int hungarian(char[][] seats) {
    final int m = seats.length;
    final int n = seats[0].length;
    int count = 0;
    int[][] seen = new int[m][n];
    int[][] match = new int[m][n];
    Arrays.stream(match).forEach(A -> Arrays.fill(A, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seats[i][j] == '.' && match[i][j] == -1) {
          final int sessionId = i * n + j;
          seen[i][j] = sessionId;
          if (dfs(seats, i, j, sessionId, seen, match))
            ++count;
        }

    return count;
  }

  private boolean dfs(char[][] seats, int i, int j, int sessionId, int[][] seen, int[][] match) {
    final int m = seats.length;
    final int n = seats[0].length;

    for (int[] dir : dirs) {
      final int x = i + dir[0];
      final int y = j + dir[1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (seats[x][y] != '.' || seen[x][y] == sessionId)
        continue;
      seen[x][y] = sessionId;
      if (match[x][y] == -1 ||
          dfs(seats, match[x][y] / n, match[x][y] % n, sessionId, seen, match)) {
        match[x][y] = i * n + j;
        match[i][j] = x * n + y;
        return true;
      }
    }

    return false;
  }
}
