class Solution {
  public int minSideJumps(int[] obstacles) {
    final int kInf = (int) 1e6;

    // dp[i] := min jump to reach lane i
    int[] dp = {kInf, 1, 0, 1};

    for (final int obstacle : obstacles) {
      if (obstacle > 0)
        dp[obstacle] = kInf;
      for (int i = 1; i <= 3; ++i) // current
        if (i != obstacle)
          for (int j = 1; j <= 3; ++j) // prev
            dp[i] = Math.min(dp[i], dp[j] + (i == j ? 0 : 1));
    }

    return Arrays.stream(dp).min().getAsInt();
  }
}
