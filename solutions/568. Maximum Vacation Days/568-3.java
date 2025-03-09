class Solution {
  public int maxVacationDays(int[][] flights, int[][] days) {
    final int N = days.length;
    final int K = days[0].length;
    // dp[i] := the number of vacations that can be taken from the i-th city
    int[] dp = new int[N];

    for (int k = K - 1; k >= 0; --k) {
      int[] newDp = new int[N];
      for (int i = 0; i < N; ++i) {
        newDp[i] = days[i][k] + dp[i];
        for (int j = 0; j < N; ++j)
          if (flights[i][j] == 1)
            newDp[i] = Math.max(newDp[i], days[j][k] + dp[j]);
      }
      dp = newDp;
    }

    return dp[0];
  }
}
