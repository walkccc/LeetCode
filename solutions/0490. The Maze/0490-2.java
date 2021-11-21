class Solution {
  public boolean hasPath(int[][] maze, int[] start, int[] destination) {
    boolean[][] seen = new boolean[maze.length][maze[0].length];
    return dfs(maze, seen, start[0], start[1], destination);
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};

  private boolean dfs(int[][] maze, boolean[][] seen, int i, int j, int[] destination) {
    if (seen[i][j])
      return false;
    if (i == destination[0] && j == destination[1])
      return true;

    seen[i][j] = true;

    for (int k = 0; k < 4; ++k) {
      int x = i;
      int y = j;
      while (isValid(maze, x + dirs[k], y + dirs[k + 1])) {
        x += dirs[k];
        y += dirs[k + 1];
      }
      if (dfs(maze, seen, x, y, destination))
        return true;
    }

    return false;
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0;
  }
}
