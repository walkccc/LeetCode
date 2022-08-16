class Solution {
  public int maxValue(int[][] events, int k) {
    // dp[i][k] := max sum of events[i:] w/ max k # of attendance
    dp = new Integer[events.length][k + 1];
    Arrays.sort(events, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
    return maxValue(events, 0, k);
  }

  private Integer[][] dp;

  private int maxValue(int[][] e, int i, int k) {
    if (k == 0 || i == e.length)
      return 0;
    if (dp[i][k] != null)
      return dp[i][k];

    final int j = binarySearch(e, i + 1, e[i][1] + 1);
    return dp[i][k] = Math.max(e[i][2] + maxValue(e, j, k - 1), maxValue(e, i + 1, k));
  }

  // find the first index l s.t e[l][0] >= target
  private int binarySearch(int[][] e, int l, int target) {
    int r = e.length;

    while (l < r) {
      final int m = (l + r) / 2;
      if (e[m][0] >= target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
}
