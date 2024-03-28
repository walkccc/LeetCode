class Solution {
  public int minCost(int n, int[] cuts) {
    int[] A = new int[cuts.length + 2];
    System.arraycopy(cuts, 0, A, 1, cuts.length);
    A[0] = 0;
    A[A.length - 1] = n;

    Arrays.sort(A);

    // dp[i][j] := minCost(cuts[i..j])
    int[][] dp = new int[A.length][A.length];

    for (int d = 2; d < A.length; ++d)
      for (int i = 0; i + d < A.length; ++i) {
        final int j = i + d;
        dp[i][j] = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = Math.min(dp[i][j], A[j] - A[i] + dp[i][k] + dp[k][j]);
      }

    return dp[0][A.length - 1];
  }
}
