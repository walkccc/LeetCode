class Solution {
 public:
  int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMax = 15;
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i][j][xors] := the number of paths from (i, j) to (m - 1, n - 1) with
    // XOR value `xors`
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(kMax + 1)));

    dp[m - 1][n - 1][grid[m - 1][n - 1]] = 1;

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        for (int xors = 0; xors <= kMax; ++xors) {
          if (i - 1 >= 0) {
            const int newXor = xors ^ grid[i - 1][j];
            dp[i - 1][j][newXor] += dp[i][j][xors];
            dp[i - 1][j][newXor] %= kMod;
          }
          if (j - 1 >= 0) {
            const int newXor = xors ^ grid[i][j - 1];
            dp[i][j - 1][newXor] += dp[i][j][xors];
            dp[i][j - 1][newXor] %= kMod;
          }
        }

    return dp[0][0][k];
  }
};
