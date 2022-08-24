class Solution {
  public String largestNumber(int[] cost, int target) {
    // dp[i] := max length that cost i can achieve
    int[] dp = new int[target + 1];
    Arrays.fill(dp, Integer.MIN_VALUE);
    dp[0] = 0; // when cost = 0, the best is empty string ""

    for (int i = 1; i <= target; ++i)
      for (int d = 0; d < 9; ++d)
        if (i >= cost[d])
          dp[i] = Math.max(dp[i], dp[i - cost[d]] + 1);

    if (dp[target] < 0)
      return "0";

    StringBuilder sb = new StringBuilder();

    // greedily build the ans string
    for (int d = 8; d >= 0; --d)
      while (target >= cost[d] && dp[target] == dp[target - cost[d]] + 1) {
        target -= cost[d];
        sb.append(1 + d);
      }

    return sb.toString();
  }
}
