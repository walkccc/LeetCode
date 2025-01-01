class Solution {
  public int buildWall(int height, int width, int[] bricks) {
    final int kMod = 1_000_000_007;
    // Stores the valid rows in bitmask.
    List<Integer> rows = new ArrayList<>();
    buildRows(width, bricks, 0, rows);

    final int n = rows.size();
    // dp[i] := the number of ways to build `h` height walls With rows[i] in the bottom
    long[] dp = new long[n];
    // graph[i] := the valid neighbors of rows[i]
    List<Integer>[] graph = new List[n];

    Arrays.fill(dp, 1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if ((rows.get(i) & rows.get(j)) == 0)
          graph[i].add(j);

    for (int h = 2; h <= height; ++h) {
      long[] newDp = new long[n];
      for (int i = 0; i < n; ++i)
        for (final int v : graph[i]) {
          newDp[i] += dp[v];
          newDp[i] %= kMod;
        }
      dp = newDp;
    }

    return (int) (Arrays.stream(dp).sum() % kMod);
  }

  private void buildRows(int width, int[] bricks, int path, List<Integer> rows) {
    for (final int brick : bricks)
      if (brick == width)
        rows.add(path);
      else if (brick < width) {
        final int newWidth = width - brick;
        buildRows(newWidth, bricks, path | 1 << newWidth, rows);
      }
  }
}
