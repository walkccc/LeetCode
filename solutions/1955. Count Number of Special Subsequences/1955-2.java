class Solution {
  public int countSpecialSubsequences(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    // dp[i][j] := the number of increasing subsequences of the first i numbers
    // that end in j
    long[][] dp = new long[n][3];

    if (nums[0] == 0)
      dp[0][0] = 1;

    for (int i = 1; i < n; ++i) {
      for (int ending = 0; ending < 3; ++ending)
        dp[i][ending] = dp[i - 1][ending];

      if (nums[i] == 0)
        // 1. The number of the previous subsequences that end in 0.
        // 2. Append a 0 to the previous subsequences that end in 0.
        // 3. Start a new subsequence from this 0.
        dp[i][0] = dp[i - 1][0] * 2 + 1;
      else if (nums[i] == 1)
        // 1. The number of the previous subsequences that end in 1.
        // 2. Append a 1 to the previous subsequences that end in 1.
        // 3. Append a 1 to the previous subsequences that end in 0.
        dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0];
      else // nums[i] == 2
        // 1. The number of the previous subsequences that end in 2.
        // 2. Append a 2 to the previous subsequences that end in 2.
        // 3. Append a 2 to the previous subsequences that end in 1.
        dp[i][2] = dp[i - 1][2] * 2 + dp[i - 1][1];

      for (int ending = 0; ending < 3; ++ending)
        dp[i][ending] %= kMod;
    }

    return (int) dp[n - 1][2];
  }
}
