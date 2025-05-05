class Solution {
 public:
  int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMax = 15;
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i][j][xors] := the number of paths from (0, 0) to (i, j) with XOR
    // value `xors`
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(kMax + 1)));

    dp[0][0][grid[0][0]] = 1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int xors = 0; xors <= kMax; ++xors) {
          if (i + 1 < m) {
            const int newXor = xors ^ grid[i + 1][j];
            dp[i + 1][j][newXor] += dp[i][j][xors];
            dp[i + 1][j][newXor] %= kMod;
          }
          if (j + 1 < n) {
            const int newXor = xors ^ grid[i][j + 1];
            dp[i][j + 1][newXor] += dp[i][j][xors];
            dp[i][j + 1][newXor] %= kMod;
          }
        }

    return dp[m - 1][n - 1][k];
  }
};
