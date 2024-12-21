class Solution {
  public int countSpecialSubsequences(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    // dp[j] := the number of increasing subsequences of the numbers so far that
    // end in j
    long[] dp = new long[3];

    if (nums[0] == 0)
      dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (nums[i] == 0)
        dp[0] = dp[0] * 2 + 1;
      else if (nums[i] == 1)
        dp[1] = dp[1] * 2 + dp[0];
      else // nums[i] == 2
        dp[2] = dp[2] * 2 + dp[1];

      for (int ending = 0; ending < 3; ++ending)
        dp[ending] %= kMod;
    }

    return (int) dp[2];
  }
}
