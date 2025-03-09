class Solution {
  public int minCost(int n, int[] cuts) {
    int[] arr = new int[cuts.length + 2];
    System.arraycopy(cuts, 0, arr, 1, cuts.length);
    arr[0] = 0;
    arr[arr.length - 1] = n;

    Arrays.sort(arr);

    // dp[i][j] := minCost(cuts[i..j])
    int[][] dp = new int[arr.length][arr.length];

    for (int d = 2; d < arr.length; ++d)
      for (int i = 0; i + d < arr.length; ++i) {
        final int j = i + d;
        dp[i][j] = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = Math.min(dp[i][j], arr[j] - arr[i] + dp[i][k] + dp[k][j]);
      }

    return dp[0][arr.length - 1];
  }
}
