class Solution {
 public:
  int minSkips(vector<int>& dist, int speed, int hoursBefore) {
    constexpr double kInf = 1e7;
    constexpr double kEps = 1e-9;
    const int n = dist.size();
    // dp[i][j] := the minimum time, where i is the number of roads we traversed
    // so far and j is the number of skips we did
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, kInf));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      const double d = dist[i - 1];
      dp[i][0] = ceil(dp[i - 1][0] + d / speed - kEps);
      for (int j = 1; j <= i; ++j)
        dp[i][j] = min(dp[i - 1][j - 1] + d / speed,
                       ceil(dp[i - 1][j] + d / speed - kEps));
    }

    for (int j = 0; j <= n; ++j)
      if (dp[n][j] <= hoursBefore)
        return j;

    return -1;
  }
};
