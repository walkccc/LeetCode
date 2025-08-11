class Solution {
  public long maxCoins(int[] lane1, int[] lane2) {
    // dp[k] := the maximum number of coins at mile so far with k switches
    long[] dp = {lane1[0], lane2[0], Long.MIN_VALUE};
    long ans = Math.max(dp[0], dp[1]);

    for (int i = 1; i < lane1.length; ++i) {
      dp = new long[] {Math.max(0, dp[0]) + lane1[i],                  //
                       Math.max(Math.max(0, dp[0]), dp[1]) + lane2[i], //
                       Math.max(dp[1], dp[2]) + lane1[i]};
      ans = Math.max(ans, Math.max(Math.max(dp[0], dp[1]), dp[2]));
    }

    return ans;
  }
}
