class Solution {
  public int countRoutes(int[] locations, int start, int finish, int fuel) {
    // dp[i][j] := the number of ways to reach `finish` from the i-th city with
    // j fuel
    dp = new Integer[locations.length][fuel + 1];
    return count(locations, start, finish, fuel);
  }

  private static final int kMod = 1_000_000_007;
  private Integer[][] dp;

  private int count(int[] locations, int i, int finish, int fuel) {
    if (fuel < 0)
      return 0;
    if (dp[i][fuel] != null)
      return dp[i][fuel];

    int res = (i == finish) ? 1 : 0;
    for (int j = 0; j < locations.length; ++j) {
      if (j == i)
        continue;
      res += count(locations, j, finish, fuel - Math.abs(locations[i] - locations[j]));
      res %= kMod;
    }

    return dp[i][fuel] = res;
  }
}
