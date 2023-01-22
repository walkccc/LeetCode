class Solution {
 public:
  double knightProbability(int N, int K, int r, int c) {
    constexpr double kProb = 0.125;
    const vector<pair<int, int>> dirs{{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                      {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    // dp[i][j] := probability to stand on (i, j)
    vector<vector<double>> dp(N, vector<double>(N));
    dp[r][c] = 1.0;

    for (int k = 0; k < K; ++k) {
      vector<vector<double>> newDp(N, vector<double>(N));
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          if (dp[i][j] > 0.0) {
            for (const auto& [dx, dy] : dirs) {
              const int x = i + dx;
              const int y = j + dy;
              if (x < 0 || x >= N || y < 0 || y >= N)
                continue;
              newDp[x][y] += dp[i][j] * kProb;
            }
          }
      dp = move(newDp);
    }

    return accumulate(begin(dp), end(dp), 0.0,
                      [](double s, vector<double>& row) {
      return s + accumulate(begin(row), end(row), 0.0);
    });
  }
};
