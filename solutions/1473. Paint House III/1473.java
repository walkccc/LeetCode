class Solution {
  public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
    // dp[k][i][prevColor] := min cost to paint houses[i..m) to k neighborhoods
    // w/ houses[i - 1]'s color = prevColor
    dp = new int[target + 1][m][n + 1];

    // init: prevColor = 0 (virtual neighbor)
    final int c = minCost(houses, cost, m, n, target, 0, 0);
    return c == kMax ? -1 : c;
  }

  private static final int kMax = (int) 1e6 + 1;
  private int[][][] dp;

  public int minCost(int[] houses, int[][] cost, int m, int n, int k, int i, int prevColor) {
    if (i == m || k < 0)
      return k == 0 ? 0 : kMax;
    if (dp[k][i][prevColor] > 0)
      return dp[k][i][prevColor];
    if (houses[i] > 0) // painted last year
      return minCost(houses, cost, m, n, k - (prevColor == houses[i] ? 0 : 1), i + 1, houses[i]);

    int ans = kMax;

    // try to paint houses[i] with each color in 1..n
    for (int color = 1; color <= n; ++color)
      ans = Math.min(ans,
                     cost[i][color - 1] + minCost(houses, cost, m, n,
                                                  k - (prevColor == color ? 0 : 1), i + 1, color));

    return dp[k][i][prevColor] = ans;
  }
}
