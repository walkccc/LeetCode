class Solution {
  public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
    dfs(maze, ball[0], ball[1], hole, 0, 0, 0, "");
    return ans;
  }

  private String ans = "impossible";
  private int minSteps = Integer.MAX_VALUE;

  private void dfs(int[][] maze, int i, int j, int[] hole, int dx, int dy, int steps,
                   final String path) {
    if (steps >= minSteps)
      return;

    if (dx != 0 || dy != 0) { // Both are zeros for the initial ball position.
      while (i + dx >= 0 && i + dx < maze.length && j + dy >= 0 && j + dy < maze[0].length &&
             maze[i + dx][j + dy] != 1) {
        i += dx;
        j += dy;
        ++steps;
        if (i == hole[0] && j == hole[1] && steps < minSteps) {
          minSteps = steps;
          ans = path;
        }
      }
    }

    if (maze[i][j] == 0 || steps + 2 < maze[i][j]) {
      maze[i][j] = steps + 2; // +2 because maze[i][j] == 0 || 1.
      if (dx == 0)
        dfs(maze, i, j, hole, 1, 0, steps, path + "d");
      if (dy == 0)
        dfs(maze, i, j, hole, 0, -1, steps, path + "l");
      if (dy == 0)
        dfs(maze, i, j, hole, 0, 1, steps, path + "r");
      if (dx == 0)
        dfs(maze, i, j, hole, -1, 0, steps, path + "u");
    }
  }
}
