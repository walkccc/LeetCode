class Solution {
  public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
    int[][][] mem = new int[target + 1][m][n + 1];
    // Initialize `prevColor` to 0 (the virtual neighbor).
    final int c = minCost(houses, cost, m, n, target, 0, 0, mem);
    return c == kMax ? -1 : c;
  }

  private static final int kMax = 1_000_001;

  // Returns the minimum cost to paint houses[i..m) into k neighborhoods, where
  // there are houses[i - 1] colors = prevColor.
  public int minCost(int[] houses, int[][] cost, int m, int n, int k, int i, int prevColor,
                     int[][][] mem) {
    if (i == m || k < 0)
      return k == 0 ? 0 : kMax;
    if (mem[k][i][prevColor] > 0)
      return mem[k][i][prevColor];
    if (houses[i] > 0) // The house was painted last year.
      return minCost(houses, cost, m, n, k - (prevColor == houses[i] ? 0 : 1), i + 1, houses[i],
                     mem);

    int ans = kMax;

    // Try to paint the houses[i] with each color in 1..n.
    for (int color = 1; color <= n; ++color)
      ans = Math.min(ans, cost[i][color - 1] + minCost(houses, cost, m, n,
                                                       k - (prevColor == color ? 0 : 1), i + 1,
                                                       color, mem));

    return mem[k][i][prevColor] = ans;
  }
}
