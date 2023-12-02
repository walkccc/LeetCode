class Solution {
  public int paintWalls(int[] cost, int[] time) {
    final int n = cost.length;
    // dp[i][j] := the minimum cost to paint j walls by the painters[i..n)
    dp = new int[n][n + 1];
    return paintWalls(cost, time, 0, time.length);
  }

  private static final int kMax = 500_000_000;
  private int[][] dp;

  private int paintWalls(int[] cost, int[] time, int i, int walls) {
    if (walls <= 0)
      return 0;
    if (i == cost.length)
      return kMax;
    if (dp[i][walls] > 0)
      return dp[i][walls];
    final int pick = cost[i] + paintWalls(cost, time, i + 1, walls - time[i] - 1);
    final int skip = paintWalls(cost, time, i + 1, walls);
    return dp[i][walls] = Math.min(pick, skip);
  }
}
