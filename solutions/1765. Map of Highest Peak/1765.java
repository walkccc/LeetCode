class Solution {
  public int[][] highestPeak(int[][] isWater) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = isWater.length;
    final int n = isWater[0].length;
    int[][] ans = new int[m][n];
    Arrays.stream(ans).forEach(A -> Arrays.fill(A, -1));
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (isWater[i][j] == 1) {
          q.offer(new Pair<>(i, j));
          ans[i][j] = 0;
        }

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (ans[x][y] != -1)
          continue;
        ans[x][y] = ans[i][j] + 1;
        q.offer(new Pair<>(x, y));
      }
    }

    return ans;
  }
}
