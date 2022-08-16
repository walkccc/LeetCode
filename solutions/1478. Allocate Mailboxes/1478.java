class Solution {
  public int minDistance(int[] houses, int k) {
    final int n = houses.length;
    // dp[i][j] := min distance to allocate i mailboxes in houses[j:]
    dp = new int[k + 1][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    // cost[i][j] := minCost to allocate mailbox between houses[i] and houses[j]
    cost = new int[n][n];

    Arrays.sort(houses);

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        final int median = houses[(i + j) / 2];
        for (int x = i; x <= j; ++x)
          cost[i][j] += Math.abs(houses[x] - median);
      }

    return minDistance(houses, k, 0);
  }

  private static final int kMax = (int) 1e6;
  private int[][] dp;
  private int[][] cost;

  private int minDistance(int[] houses, int k, int i) {
    if (k == 0 && i == houses.length)
      return 0;
    if (k == 0 || i == houses.length)
      return kMax;
    if (dp[k][i] != Integer.MAX_VALUE)
      return dp[k][i];

    for (int j = i; j < houses.length; ++j)
      dp[k][i] = Math.min(dp[k][i], cost[i][j] + minDistance(houses, k - 1, j + 1));

    return dp[k][i];
  }
}
