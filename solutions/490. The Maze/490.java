class Solution {
  public boolean hasPath(int[][] maze, int[] start, int[] destination) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = maze.length;
    final int n = maze[0].length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(start[0], start[1])));
    boolean[][] seen = new boolean[m][n];
    seen[start[0]][start[1]] = true;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : DIRS) {
        int x = i;
        int y = j;
        while (isValid(maze, x + dir[0], y + dir[1])) {
          x += dir[0];
          y += dir[1];
        }
        if (x == destination[0] && y == destination[1])
          return true;
        if (seen[x][y])
          continue;
        q.offer(new Pair<>(x, y));
        seen[x][y] = true;
      }
    }

    return false;
  }

  private boolean isValid(int[][] maze, int x, int y) {
    return 0 <= x && x < maze.length && 0 <= y && y < maze[0].length && maze[x][y] == 0;
  }
}
