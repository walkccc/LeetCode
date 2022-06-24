class Solution {
 public:
  int removeOnes(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int maxMask = 1 << m * n;
    // dp[i] := min # of operations to remove all 1's from grid
    // given i representing the state of grid
    vector<int> dp(maxMask, INT_MAX / 2);
    dp[0] = 0;

    for (int mask = 0; mask < maxMask; ++mask)
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j]) {
            int nextMask = mask;
            for (int k = 0; k < n; ++k)  // set cell in the same row with 0
              nextMask &= ~(1 << i * n + k);
            for (int k = 0; k < m; ++k)  // set cell in the same col with 0
              nextMask &= ~(1 << k * n + j);
            dp[mask] = min(dp[mask], 1 + dp[nextMask]);
          }

    return dp[encode(grid, m, n)];
  }

 private:
  int encode(const vector<vector<int>>& grid, int m, int n) {
    int encoded = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j])
          encoded |= 1 << i * n + j;
    return encoded;
  }
};
