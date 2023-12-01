class Solution {
  public int getMoneyAmount(int n) {
    // dp[i][j] := the minimum money you need to guarantee a win of picking i..j
    dp = new int[n + 1][n + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    return getMoneyAmount(1, n);
  }

  private int[][] dp;

  private int getMoneyAmount(int i, int j) {
    if (i >= j)
      return 0;
    if (dp[i][j] != Integer.MAX_VALUE)
      return dp[i][j];

    for (int k = i; k <= j; ++k)
      dp[i][j] = Math.min(dp[i][j], //
                          Math.max(getMoneyAmount(i, k - 1), getMoneyAmount(k + 1, j)) + k);

    return dp[i][j];
  }
}
