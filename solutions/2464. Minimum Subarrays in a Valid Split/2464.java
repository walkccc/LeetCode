class Solution {
  public int validSubarraySplit(int[] nums) {
    final int kMax = Integer.MAX_VALUE / 2;
    final int n = nums.length;
    // dp[i] := the minimum number of subarrays to validly split nums[0..i]
    int[] dp = new int[n];
    Arrays.fill(dp, kMax);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= i; ++j)
        if (gcd(nums[j], nums[i]) > 1)
          dp[i] = Math.min(dp[i], j == 0 ? 1 : dp[j - 1] + 1);

    return dp[n - 1] == kMax ? -1 : dp[n - 1];
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
