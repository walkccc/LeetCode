class Solution {
  public int maxScore(int[] nums) {
    final int n = nums.length / 2;
    dp = new int[n + 1][1 << (n * 2)];
    return maxScore(nums, 1, 0);
  }

  private int[][] dp;

  private int maxScore(int[] nums, int op, int mask) {
    if (op == dp.length)
      return 0;
    if (dp[op][mask] > 0)
      return dp[op][mask];

    for (int i = 0; i < nums.length; ++i)
      for (int j = i + 1; j < nums.length; ++j) {
        final int chosenMask = 1 << i | 1 << j;
        if ((mask & chosenMask) == 0)
          dp[op][mask] = Math.max(dp[op][mask], op * gcd(nums[i], nums[j]) +
                                                    maxScore(nums, op + 1, mask | chosenMask));
      }

    return dp[op][mask];
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
