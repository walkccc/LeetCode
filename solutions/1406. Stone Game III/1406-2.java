class Solution {
  public String stoneGameIII(int[] stoneValue) {
    final int n = stoneValue.length;
    // dp[i] := max "relative score" Alice can make w/ stoneValue[i:]
    int[] dp = new int[n + 1];
    Arrays.fill(dp, 0, n, Integer.MIN_VALUE / 2);

    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      for (int j = i; j < i + 3 && j < n; ++j) {
        sum += stoneValue[j];
        dp[i] = Math.max(dp[i], sum - dp[j + 1]);
      }
    }

    final int score = dp[0];
    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }
}
