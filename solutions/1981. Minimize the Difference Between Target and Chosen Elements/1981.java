class Solution {
  public int minimizeTheDifference(int[][] mat, int target) {
    final int minSum =
        Arrays.stream(mat).mapToInt(row -> Arrays.stream(row).min().getAsInt()).sum();
    if (minSum >= target) // No need to consider any larger combination.
      return minSum - target;

    final int maxSum =
        Arrays.stream(mat).mapToInt(row -> Arrays.stream(row).max().getAsInt()).sum();
    dp = new Integer[mat.length][maxSum + 1];
    return minimizeTheDifference(mat, 0, 0, target);
  }

  private Integer[][] dp;

  private int minimizeTheDifference(int[][] mat, int i, int sum, int target) {
    if (i == mat.length)
      return Math.abs(sum - target);
    if (dp[i][sum] != null)
      return dp[i][sum];
    int ans = Integer.MAX_VALUE;
    for (final int num : mat[i])
      ans = Math.min(ans, minimizeTheDifference(mat, i + 1, sum + num, target));
    return dp[i][sum] = ans;
  }
}
