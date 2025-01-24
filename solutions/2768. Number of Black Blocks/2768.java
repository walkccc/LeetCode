class Solution {
  public long[] countBlackBlocks(int m, int n, int[][] coordinates) {
    long[] ans = new long[5];
    // count[i * n + j] := the number of black cells in
    // (i - 1, j - 1), (i - 1, j), (i, j - 1), (i, j)
    Map<Long, Integer> count = new HashMap<>();

    for (int[] coordinate : coordinates) {
      final int x = coordinate[0];
      final int y = coordinate[1];
      for (long i = x; i < x + 2; ++i)
        for (long j = y; j < y + 2; ++j)
          // 2 x 2 submatrix with right-bottom conner being (i, j) contains the
          // current black cell (x, y).
          if (i - 1 >= 0 && i < m && j - 1 >= 0 && j < n)
            count.merge(i * n + j, 1, Integer::sum);
    }

    for (final int freq : count.values())
      ++ans[freq];

    ans[0] = (m - 1L) * (n - 1) - Arrays.stream(ans).sum();
    return ans;
  }
}
