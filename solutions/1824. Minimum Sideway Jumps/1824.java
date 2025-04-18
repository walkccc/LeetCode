class Solution {
  public int minSideJumps(int[] obstacles) {
    final int INF = 1_000_000;
    // dp[i] := the minimum jump to reach the i-th lane
    int[] dp = {INF, 1, 0, 1};

    for (final int obstacle : obstacles) {
      if (obstacle > 0)
        dp[obstacle] = INF;
      for (int i = 1; i <= 3; ++i) // the current
        if (i != obstacle)
          for (int j = 1; j <= 3; ++j) // the previous
            dp[i] = Math.min(dp[i], dp[j] + (i == j ? 0 : 1));
    }

    return Arrays.stream(dp).min().getAsInt();
  }
}
