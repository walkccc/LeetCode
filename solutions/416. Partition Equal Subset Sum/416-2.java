class Solution {
  public boolean canPartition(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    if (sum % 2 == 1)
      return false;

    return knapsack(nums, sum / 2);
  }

  private boolean knapsack(int[] nums, int subsetSum) {
    // dp[i] := true if i can be formed by nums so far
    boolean[] dp = new boolean[subsetSum + 1];
    dp[0] = true;

    for (final int num : nums)
      for (int i = subsetSum; i >= num; --i)
        dp[i] = dp[i] || dp[i - num];

    return dp[subsetSum];
  }
}
