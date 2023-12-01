class Solution {
  public int maximumScore(int[] nums, int[] multipliers) {
    // dp[s][i] := the maximum score of nums[s..e] and multipliers[i]
    dp = new Integer[multipliers.length][multipliers.length];
    return maximumScore(nums, 0, multipliers, 0);
  }

  private Integer[][] dp;

  int maximumScore(int[] nums, int s, int[] multipliers, int i) {
    if (i == multipliers.length)
      return 0;
    if (dp[s][i] != null)
      return dp[s][i];

    // The number of nums picked on the start side is s.
    // The number of nums picked on the end side is i - s.
    // So, e = n - (i - s) - 1.
    final int e = nums.length - (i - s) - 1;
    final int pickStart = nums[s] * multipliers[i] + maximumScore(nums, s + 1, multipliers, i + 1);
    final int pickEnd = nums[e] * multipliers[i] + maximumScore(nums, s, multipliers, i + 1);
    return dp[s][i] = Math.max(pickStart, pickEnd);
  }
}
