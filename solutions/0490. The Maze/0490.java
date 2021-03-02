class Solution {
  public boolean hasPath(int[][] maze, int[] start, int[] destination) {
    final int m = maze.length;
    final int n = maze[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};

    Queue<int[]> q = new LinkedList<>(Arrays.asList(new int[] {start[0], start[1]}));
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
        if (seen[x][y])
          continue;
        if (x == destination[0] && y == destination[1])
          return true;
        q.offer(new int[] {x, y});
        seen[x][y] = true;
      }
    }

    return false;
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0;
  }
}
