class Solution {
  public boolean canPartition(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    if (sum % 2 == 1)
      return false;

    return subsetSum(nums, sum / 2);
  }

  private boolean subsetSum(final int[] nums, int target) {
    boolean[] dp = new boolean[target + 1]; // dp[i] := true if can sum to i
    dp[0] = true;

    for (final int num : nums)
      for (int w = target; w >= num; --w)
        dp[w] = dp[w] || dp[w - num];

    return dp[target];
  }
}