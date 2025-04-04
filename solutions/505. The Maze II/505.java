class Solution {
  public int shortestDistance(int[][] maze, int[] start, int[] destination) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = maze.length;
    final int n = maze[0].length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(start[0], start[1])));
    int[][] dist = new int[maze.length][maze[0].length];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    dist[start[0]][start[1]] = 0;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : DIRS) {
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
          q.offer(new Pair<>(x, y));
        }
      }
    }

    return dist[destination[0]][destination[1]] == Integer.MAX_VALUE
        ? -1
        : dist[destination[0]][destination[1]];
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0;
  }
}
