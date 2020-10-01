class Solution {
  public int findTargetSumWays(int[] nums, int S) {
    final int sum = Arrays.stream(nums).sum();
    if (sum < S || (sum + S) % 2 == 1)
      return 0;

    return subsetSum(nums, (sum + S) / 2);
  }

  private int subsetSum(final int[] nums, int target) {
    int[] dp = new int[target + 1]; // dp[i] := # of ways to sum to i
    dp[0] = 1;

    for (final int num : nums)
      for (int w = target; w >= num; --w)
        dp[w] += dp[w - num];

    return dp[target];
  }
}