class Solution {
  public int winningPlayerCount(int n, int[][] pick) {
    final int kMaxColor = 10;
    int ans = 0;
    int[][] counts = new int[n][kMaxColor + 1];

    for (int[] p : pick) {
      final int player = p[0];
      final int color = p[1];
      ++counts[player][color];
    }

    for (int i = 0; i < n; ++i) {
      int maxCount = 0;
      for (final int freq : counts[i])
        maxCount = Math.max(maxCount, freq);
      if (maxCount > i)
        ++ans;
    }

    return ans;
  }
}
