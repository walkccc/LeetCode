class Solution {
  public String largestNumber(int[] cost, int target) {
    // dp[i] := the maximum length that cost i can achieve
    int[] dp = new int[target + 1];
    Arrays.fill(dp, Integer.MIN_VALUE);
    dp[0] = 0; // If cost = 0, the best choice is the empty string "".

    for (int i = 1; i <= target; ++i)
      for (int d = 0; d < 9; ++d)
        if (i >= cost[d])
          dp[i] = Math.max(dp[i], dp[i - cost[d]] + 1);

    if (dp[target] < 0)
      return "0";

    StringBuilder sb = new StringBuilder();

    // Greedily build the ans string.
    for (int d = 8; d >= 0; --d)
      while (target >= cost[d] && dp[target] == dp[target - cost[d]] + 1) {
        target -= cost[d];
        sb.append(1 + d);
      }

    return sb.toString();
  }
}
