class Solution {
  public int findTargetSumWays(int[] nums, int target) {
    final int sum = Arrays.stream(nums).sum();
    if (sum < Math.abs(target) || (sum + target) % 2 == 1)
      return 0;
    return knapsack(nums, (sum + target) / 2);
  }

  private int knapsack(int[] nums, int target) {
    final int n = nums.length;
    // dp[i][j] := # of ways to sum to j by nums[0..i)
    int[][] dp = new int[n + 1][target + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      final int num = nums[i - 1];
      for (int j = 0; j <= target; ++j)
        if (j < num)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
    }

    return dp[n][target];
  }
}
