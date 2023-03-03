class Solution {
  public String stoneGameIII(int[] stoneValue) {
    // dp[i] := max "relative score" Alice can make w/ stoneValue[i:]
    dp = new int[stoneValue.length];
    Arrays.fill(dp, Integer.MIN_VALUE);

    final int score = stoneGameIII(stoneValue, 0);
    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }

  private int[] dp;

  private int stoneGameIII(int[] stoneValue, int i) {
    if (i == stoneValue.length)
      return 0;
    if (dp[i] > Integer.MIN_VALUE)
      return dp[i];

    int sum = 0;
    for (int j = i; j < i + 3 && j < stoneValue.length; ++j) {
      sum += stoneValue[j];
      dp[i] = Math.max(dp[i], sum - stoneGameIII(stoneValue, j + 1));
    }

    return dp[i];
  };
}
