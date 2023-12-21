class Solution {
 public:
  double knightProbability(int n, int k, int row, int column) {
    constexpr double kProb = 0.125;
    const vector<pair<int, int>> dirs{{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                      {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    // dp[i][j] := the probability to stand on (i, j)
    vector<vector<double>> dp(n, vector<double>(n));
    dp[row][column] = 1.0;

    for (int move = 0; move < k; ++move) {
      vector<vector<double>> newDp(n, vector<double>(n));
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (dp[i][j] > 0.0) {
            for (const auto& [dx, dy] : dirs) {
              const int x = i + dx;
              const int y = j + dy;
              if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
              newDp[x][y] += dp[i][j] * kProb;
            }
          }
      dp = std::move(newDp);
    }

    return accumulate(dp.begin(), dp.end(), 0.0,
                      [](double subtotal, const vector<double>& row) {
      return subtotal + accumulate(row.begin(), row.end(), 0.0);
    });
  }
};
