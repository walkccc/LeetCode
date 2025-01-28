class Solution {
  public int shortestDistance(int[][] maze, int[] start, int[] destination) {
    int[][] dist = new int[maze.length][maze[0].length];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    dist[start[0]][start[1]] = 0;

    dfs(maze, dist, start[0], start[1], destination);

    return dist[destination[0]][destination[1]] == Integer.MAX_VALUE
        ? -1
        : dist[destination[0]][destination[1]];
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private void dfs(int[][] maze, int[][] dist, int i, int j, int[] destination) {
    if (i == destination[0] && j == destination[1])
      return;

    for (int[] dir : dirs) {
      int x = i;
      int y = j;
      int step = dist[i][j];
      while (isValid(maze, x + dir[0], y + dir[1])) {
        x += dir[0];
        y += dir[1];
        ++step;
      }
      if (step < dist[x][y]) {
        dist[x][y] = step;
        dfs(maze, dist, x, y, destination);
      }
    }
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0;
  }
}
