class Solution {
  public int minCost(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    dp = new int[m][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();

    dfs(grid, 0, 0, /*cost=*/0, q);

    for (int cost = 1; !q.isEmpty(); ++cost)
      for (int sz = q.size(); sz > 0; --sz) {
        Pair<Integer, Integer> node = q.poll();
        final int i = node.getKey();
        final int j = node.getValue();
        for (int[] dir : dirs)
          dfs(grid, i + dir[0], j + dir[1], cost, q);
      }

    return dp[m - 1][n - 1];
  }

  private static final int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  private int[][] dp;

  private void dfs(int[][] grid, int i, int j, int cost, Queue<Pair<Integer, Integer>> q) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (dp[i][j] != -1)
      return;

    dp[i][j] = cost;
    q.add(new Pair<>(i, j));
    int[] dir = dirs[grid[i][j] - 1];
    dfs(grid, i + dir[0], j + dir[1], cost, q);
  }
}
