class Solution {
  public boolean hasPath(int[][] maze, int[] start, int[] destination) {
    boolean[][] seen = new boolean[maze.length][maze[0].length];
    return dfs(maze, seen, start[0], start[1], destination);
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private boolean dfs(int[][] maze, boolean[][] seen, int i, int j, int[] destination) {
    if (i == destination[0] && j == destination[1])
      return true;
    if (seen[i][j])
      return false;

    seen[i][j] = true;

    for (int[] dir : dirs) {
      int x = i;
      int y = j;
      while (isValid(maze, x + dir[0], y + dir[1])) {
        x += dir[0];
        y += dir[1];
      }
      if (dfs(maze, seen, x, y, destination))
        return true;
    }

    return false;
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return 0 <= x && x < maze.length && 0 <= y && y < maze[0].length && maze[x][y] == 0;
  }
}
