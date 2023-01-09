class Solution {
  public int minCost(int n, int[] cuts) {
    A = new int[cuts.length + 2];
    System.arraycopy(cuts, 0, A, 1, cuts.length);
    A[0] = 0;
    A[A.length - 1] = n;

    Arrays.sort(A);

    // dp[i][j] := minCost(cuts[i..j])
    dp = new int[A.length][A.length];
    return minCost(0, A.length - 1);
  }

  private int[][] dp;
  private int[] A;

  private int minCost(int i, int j) {
    if (j - i <= 1)
      return 0;
    if (dp[i][j] != 0)
      return dp[i][j];

    dp[i][j] = Integer.MAX_VALUE;

    for (int k = i + 1; k < j; ++k)
      dp[i][j] = Math.min(dp[i][j], A[j] - A[i] + minCost(i, k) + minCost(k, j));

    return dp[i][j];
  }
}
