class Solution {
  public int rob(int[] nums) {
    int prev1 = 0; // dp[i - 1]
    int prev2 = 0; // dp[i - 2]

    for (final int num : nums) {
      final int dp = Math.max(prev1, prev2 + num);
      prev2 = prev1;
      prev1 = dp;
    }

    return prev1;
  }
}
