class Solution {
  public int maxVacationDays(int[][] flights, int[][] days) {
    // dp[i][j] := the number of vacations that can be taken from the i-th city
    // and the k-th week
    dp = new int[days.length][days[0].length];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MIN_VALUE));
    return maxVacationDays(flights, days, 0, 0);
  }

  private int[][] dp;

  private int maxVacationDays(int[][] flights, int[][] days, int i, int k) {
    if (k == days[0].length)
      return 0;
    if (dp[i][k] != Integer.MIN_VALUE)
      return dp[i][k];

    int ans = 0;

    // Stay at the j-th city or fly from the i-th city to the j-th city.
    for (int j = 0; j < flights.length; ++j)
      if (j == i || flights[i][j] == 1)
        ans = Math.max(ans, days[j][k] + maxVacationDays(flights, days, j, k + 1));

    return dp[i][k] = ans;
  }
}
