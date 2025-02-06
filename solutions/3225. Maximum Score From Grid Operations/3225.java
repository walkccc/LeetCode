class Solution {
  public long maximumScore(int[][] grid) {
    final int n = grid.length;
    // prefix[j][i] := the sum of the first i elements in the j-th column
    long[][] prefix = new long[n][n + 1];
    // prevPick[i] := the maximum achievable score up to the previous column,
    // where the bottommost selected element in that column is in row (i - 1)
    long[] prevPick = new long[n + 1];
    // prevSkip[i] := the maximum achievable score up to the previous column,
    // where the bottommost selected element in the column before the previous
    // one is in row (i - 1)
    long[] prevSkip = new long[n + 1];

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < n; ++i)
        prefix[j][i + 1] = prefix[j][i] + grid[i][j];

    for (int j = 1; j < n; ++j) {
      long[] currPick = new long[n + 1];
      long[] currSkip = new long[n + 1];
      // Consider all possible combinations of the number of current and
      // previous selected elements.
      for (int curr = 0; curr <= n; ++curr)
        for (int prev = 0; prev <= n; ++prev)
          if (curr > prev) {
            // 1. The current bottom is deeper than the previous bottom.
            // Get the score of grid[prev..curr)[j - 1] for pick and skip.
            final long score = prefix[j - 1][curr] - prefix[j - 1][prev];
            currPick[curr] = Math.max(currPick[curr], prevSkip[prev] + score);
            currSkip[curr] = Math.max(currSkip[curr], prevSkip[prev] + score);
          } else {
            // 2. The previous bottom is deeper than the current bottom.
            // Get the score of grid[curr..prev)[j] for pick only.
            final long score = prefix[j][prev] - prefix[j][curr];
            currPick[curr] = Math.max(currPick[curr], prevPick[prev] + score);
            currSkip[curr] = Math.max(currSkip[curr], prevPick[prev]);
          }
      prevPick = currPick;
      prevSkip = currSkip;
    }

    return Arrays.stream(prevPick).max().getAsLong();
  }
}
