class Solution {
  public int maxScore(int n, int k, int[][] stayScore, int[][] travelScore) {
    // dp[i][j] := the maximum score after i days being at city j
    int[][] dp = new int[k + 1][n];

    for (int i = 1; i <= k; ++i) {
      for (int dest = 0; dest < n; ++dest) {
        // 1. Stay at the current city.
        dp[i][dest] = dp[i - 1][dest] + stayScore[i - 1][dest];
        // 2. Travel from any other city.
        for (int curr = 0; curr < n; ++curr)
          if (curr != dest)
            dp[i][dest] = Math.max(dp[i][dest], dp[i - 1][curr] + travelScore[curr][dest]);
      }
    }

    return Arrays.stream(dp[k]).max().getAsInt();
  }
}
