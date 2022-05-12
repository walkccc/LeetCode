class Solution {
  public int findTargetSumWays(int[] nums, int S) {
    final int sum = Arrays.stream(nums).sum();
    if (sum < S || (sum + S) % 2 == 1)
      return 0;

    return knapsack(nums, (sum + S) / 2);
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
