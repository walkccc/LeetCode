class Solution {
  public long mostPoints(int[][] questions) {
    final int n = questions.length;
    // dp[i] := the maximum points starting from questions[i]
    long[] dp = new long[n + 1];

    for (int i = n - 1; i >= 0; --i) {
      final int points = questions[i][0];
      final int brainpower = questions[i][1];
      final int nextIndex = i + brainpower + 1;
      final long nextPoints = nextIndex < n ? dp[nextIndex] : 0;
      dp[i] = Math.max(points + nextPoints, dp[i + 1]);
    }

    return dp[0];
  }
}
