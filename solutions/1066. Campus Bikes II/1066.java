class Solution {
  public int assignBikes(int[][] workers, int[][] bikes) {
    // dp[i] := the minimum distance to assign bikes j (bitmask)
    dp = new int[1 << bikes.length];
    return assignBikes(workers, bikes, 0, 0);
  }

  private int[] dp;

  private int assignBikes(int[][] workers, int[][] bikes, int s, int bikeUsed) {
    if (s == workers.length)
      return 0;
    if (dp[bikeUsed] > 0)
      return dp[bikeUsed];

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < bikes.length; ++i) {
      if ((bikeUsed >> i & 1) == 1)
        continue;
      ans = Math.min(ans, dist(workers[s], bikes[i]) +
                              assignBikes(workers, bikes, s + 1, bikeUsed | 1 << i));
    }

    return dp[bikeUsed] = ans;
  }

  private int dist(int[] p1, int[] p2) {
    return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
  }
}
