class Solution {
  public int findTargetSumWays(int[] nums, int target) {
    final int sum = Arrays.stream(nums).sum();
    if (sum < Math.abs(target) || (sum + target) % 2 == 1)
      return 0;
    return knapsack(nums, (sum + target) / 2);
  }

  private int knapsack(int[] nums, int target) {
    // dp[i] := # of ways to sum to i by nums so far
    int[] dp = new int[target + 1];
    dp[0] = 1;

    for (final int num : nums)
      for (int i = target; i >= num; --i)
        dp[i] += dp[i - num];

    return dp[target];
  }
}
