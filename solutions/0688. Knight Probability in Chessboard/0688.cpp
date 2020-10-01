class Solution {
 public:
  double knightProbability(int N, int K, int r, int c) {
    constexpr double kProb = 0.125;
    const vector<pair<int, int>> dirs{{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                      {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    vector<vector<double>> dp(N, vector<double>(N));
    dp[r][c] = 1;

    for (int k = 0; k < K; ++k) {
      vector<vector<double>> newDp(N, vector<double>(N));
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          if (dp[i][j] > 0.0) {
            for (const auto& [dx, dy] : dirs) {
              const int x = i + dx;
              const int y = j + dy;
              if (x < 0 || x >= N || y < 0 || y >= N) continue;
              newDp[x][y] += dp[i][j] * kProb;
            }
          }
      swap(dp, newDp);
    }

    double ans = 0;
    for (const vector<double>& row : dp)
      ans += accumulate(begin(row), end(row), 0.0);

    return ans;
  }
};