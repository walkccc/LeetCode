class Solution {
  public boolean canPartition(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    if (sum % 2 == 1)
      return false;
    return knapsack(nums, sum / 2);
  }

  private boolean knapsack(int[] nums, int subsetSum) {
    final int n = nums.length;
    // dp[i][j] := true if j can be formed by nums[0..i)
    boolean[][] dp = new boolean[n + 1][subsetSum + 1];
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
      final int num = nums[i - 1];
      for (int j = 0; j <= subsetSum; ++j)
        if (j < num)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
    }

    return dp[n][subsetSum];
  }
}
