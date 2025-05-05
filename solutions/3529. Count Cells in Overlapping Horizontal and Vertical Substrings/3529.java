class Solution {
  public int countCells(char[][] grid, String pattern) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    StringBuilder flattenedGridRow = new StringBuilder();
    StringBuilder flattenedGridCol = new StringBuilder();

    // Flatten the grid for horizontal matching.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        flattenedGridRow.append(grid[i][j]);

    // Flatten the grid for vertical matching.
    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i)
        flattenedGridCol.append(grid[i][j]);

    // Find matching positions.
    boolean[][] horizontalMatches =
        markMatchedCells(flattenedGridRow.toString(), pattern, m, n, true);
    boolean[][] verticalMatches =
        markMatchedCells(flattenedGridCol.toString(), pattern, m, n, false);

    // Count overlapping match positions.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (horizontalMatches[i][j] && verticalMatches[i][j])
          ++ans;

    return ans;
  }

  private static final long BASE = 13;
  private static final long HASH = 1_000_000_007;

  private boolean[][] markMatchedCells(final String flattenedGrid, final String pattern, int m,
                                       int n, boolean isHorizontal) {
    boolean[][] matchMatrix = new boolean[m][n];
    int[] matchPrefix = new int[flattenedGrid.length() + 1];
    long[] pows = new long[pattern.length()]; // pows[i] := BASE^i % HASH
    pows[0] = 1;
    long patternHash = 0;
    long runningHash = 0;

    for (int i = 1; i < pattern.length(); ++i)
      pows[i] = (pows[i - 1] * BASE) % HASH;

    for (final char c : pattern.toCharArray())
      patternHash = (patternHash * BASE + (c - 'a')) % HASH;

    for (int i = 0; i < flattenedGrid.length(); ++i) {
      runningHash = (runningHash * BASE + (flattenedGrid.charAt(i) - 'a')) % HASH;
      if (i >= pattern.length() - 1) {
        if (runningHash == patternHash) { // Match found.
          ++matchPrefix[i - pattern.length() + 1];
          --matchPrefix[i + 1];
        }
        // Remove the contribution of the oldest letter.
        final long oldestLetterHash =
            (pows[pattern.length() - 1] * (flattenedGrid.charAt(i - pattern.length() + 1) - 'a')) %
            HASH;
        runningHash = (runningHash - oldestLetterHash + HASH) % HASH;
      }
    }

    for (int k = 0; k < flattenedGrid.length(); ++k) {
      matchPrefix[k] += (k > 0) ? matchPrefix[k - 1] : 0;
      if (matchPrefix[k] > 0) {
        final int i = isHorizontal ? k / n : k % m;
        final int j = isHorizontal ? k % n : k / m;
        matchMatrix[i][j] = true;
      }
    }

    return matchMatrix;
  }
}
