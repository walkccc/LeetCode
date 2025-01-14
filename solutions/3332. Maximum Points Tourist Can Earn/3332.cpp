class Solution {
 public:
  int maxScore(int n, int k, vector<vector<int>>& stayScore,
               vector<vector<int>>& travelScore) {
    // dp[i][j] := the maximum score after i days being at city j
    vector<vector<int>> dp(k + 1, vector<int>(n));

    for (int i = 1; i <= k; ++i)
      for (int dest = 0; dest < n; ++dest) {
        // 1. Stay at the current city.
        dp[i][dest] = dp[i - 1][dest] + stayScore[i - 1][dest];
        // 2. Travel from any other city.
        for (int curr = 0; curr < n; ++curr)
          if (curr != dest)
            dp[i][dest] =
                max(dp[i][dest], dp[i - 1][curr] + travelScore[curr][dest]);
      }

    return ranges::max(dp[k]);
  }
};
