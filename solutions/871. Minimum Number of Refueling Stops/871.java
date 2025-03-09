class Solution {
  public int minRefuelStops(int target, int startFuel, int[][] stations) {
    // dp[i] := the farthest position we can reach with i refuels
    long dp[] = new long[stations.length + 1];
    dp[0] = startFuel;

    for (int i = 0; i < stations.length; ++i)
      for (int j = i + 1; j > 0; --j)
        if (dp[j - 1] >= stations[i][0])
          dp[j] = Math.max(dp[j], dp[j - 1] + stations[i][1]);

    for (int i = 0; i < dp.length; ++i)
      if (dp[i] >= target)
        return i;

    return -1;
  }
}
