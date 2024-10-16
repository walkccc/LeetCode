class Solution {
  public int maximizeWin(int[] prizePositions, int k) {
    int ans = 0;
    // dp[i] := the maximum number of prizes to choose the first i
    // `prizePositions`
    int[] dp = new int[prizePositions.length + 1];

    for (int i = 0, j = 0; i < prizePositions.length; ++i) {
      while (prizePositions[i] - prizePositions[j] > k)
        ++j;
      final int covered = i - j + 1;
      dp[i + 1] = Math.max(dp[i], covered);
      ans = Math.max(ans, dp[j] + covered);
    }

    return ans;
  }
}
