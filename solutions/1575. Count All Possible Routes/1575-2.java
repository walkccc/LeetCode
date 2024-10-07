class Solution {
  public int countRoutes(int[] locations, int start, int finish, int fuel) {
    final int kMod = 1_000_000_007;
    int n = locations.length;
    // dp[i][j] := the number of ways to reach the `finish` city from the i-th
    // city with `j` fuel
    int[][] dp = new int[n][fuel + 1];

    for (int f = 0; f <= fuel; ++f)
      dp[finish][f] = 1;

    for (int f = 0; f <= fuel; ++f)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          if (i == j)
            continue;
          final int requiredFuel = Math.abs(locations[i] - locations[j]);
          if (requiredFuel <= f) {
            dp[i][f] += dp[j][f - requiredFuel];
            dp[i][f] %= kMod;
          }
        }

    return dp[start][fuel];
  }
}
