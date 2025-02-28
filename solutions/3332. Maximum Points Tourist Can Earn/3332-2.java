class Solution {
  public int maxScore(int n, int k, int[][] stayScore, int[][] travelScore) {
    // dp[j] := the maximum score after days so far being at city j
    int[] dp = new int[n];

    for (int i = 0; i < k; ++i) {
      int[] newDp = new int[n];
      for (int dest = 0; dest < n; ++dest) {
        // 1. Stay at the current city.
        newDp[dest] = dp[dest] + stayScore[i][dest];
        // 2. Travel from any other city.
        for (int curr = 0; curr < n; ++curr)
          if (curr != dest)
            newDp[dest] = Math.max(newDp[dest], dp[curr] + travelScore[curr][dest]);
      }
      dp = newDp; // Update dp for the next day
    }

    return Arrays.stream(dp).max().getAsInt();
  }
}
