class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    // dp[i][j] := the number of paths to move the ball (i, j) out-of-bounds
    vector<vector<int>> dp(m, vector<int>(n));
    dp[startRow][startColumn] = 1;

    while (maxMove--) {
      vector<vector<int>> newDp(m, vector<int>(n));
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (dp[i][j] > 0)
            for (const auto& [dx, dy] : dirs) {
              const int x = i + dx;
              const int y = j + dy;
              if (x < 0 || x == m || y < 0 || y == n)
                ans = (ans + dp[i][j]) % kMod;
              else
                newDp[x][y] = (newDp[x][y] + dp[i][j]) % kMod;
            }
      dp = std::move(newDp);
    }

    return ans;
  }
};
