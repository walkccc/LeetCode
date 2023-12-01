class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    constexpr int kMod = 1'000'000'007;
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;
    // dp[i][j] := the number of paths to move the ball (i, j) out-of-bounds
    vector<vector<int>> dp(m, vector<int>(n));
    dp[startRow][startColumn] = 1;

    while (maxMove--) {
      vector<vector<int>> newDp(m, vector<int>(n));
      for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
          if (dp[r][c] > 0)
            for (int k = 0; k < 4; ++k) {
              const int x = r + dirs[k];
              const int y = c + dirs[k + 1];
              if (x < 0 || x == m || y < 0 || y == n)
                ans = (ans + dp[r][c]) % kMod;
              else
                newDp[x][y] = (newDp[x][y] + dp[r][c]) % kMod;
            }
      dp = move(newDp);
    }

    return ans;
  }
};
