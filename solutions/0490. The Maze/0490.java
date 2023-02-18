class Solution {
  public boolean hasPath(int[][] maze, int[] start, int[] destination) {
    final int m = maze.length;
    final int n = maze[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(new int[] {start[0], start[1]}));
    boolean[][] seen = new boolean[m][n];
    seen[start[0]][start[1]] = true;

    while (!q.isEmpty()) {
      final int i = q.peek()[0];
      final int j = q.poll()[1];
      for (int k = 0; k < 4; ++k) {
        int x = i;
        int y = j;
        while (isValid(maze, x + dirs[k], y + dirs[k + 1])) {
          x += dirs[k];
          y += dirs[k + 1];
        }
        if (x == destination[0] && y == destination[1])
          return true;
        if (seen[x][y])
          continue;
        q.offer(new int[] {x, y});
        seen[x][y] = true;
      }
    }

    return false;
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return 0 <= x && x < maze.length && 0 <= y && y < maze[0].length && maze[x][y] == 0;
  }
}
