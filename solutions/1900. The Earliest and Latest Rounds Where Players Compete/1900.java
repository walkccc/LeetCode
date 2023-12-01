class Solution {
  public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    // dp[i][j][k] := the (earliest, latest) pair, the first player is the i-th
    // player from the front, the second player is the j-th player from the end,
    // and there're k people
    dp = new int[n + 1][n + 1][n + 1][2];
    return solve(firstPlayer, n - secondPlayer + 1, n);
  }

  private int[][][][] dp;

  private int[] solve(int l, int r, int k) {
    if (l == r)
      return new int[] {1, 1};
    if (l > r)
      return solve(r, l, k);
    if (!Arrays.equals(dp[l][r][k], new int[] {0, 0}))
      return dp[l][r][k];

    int a = Integer.MAX_VALUE;
    int b = Integer.MIN_VALUE;

    // Enumerate all the possible positions.
    for (int i = 1; i <= l; ++i)
      for (int j = l - i + 1; j <= r - i; ++j) {
        if (i + j > (k + 1) / 2 || i + j < l + r - k / 2)
          continue;
        int[] res = solve(i, j, (k + 1) / 2);
        a = Math.min(a, res[0] + 1);
        b = Math.max(b, res[1] + 1);
      }

    return dp[l][r][k] = new int[] {a, b};
  }
}
