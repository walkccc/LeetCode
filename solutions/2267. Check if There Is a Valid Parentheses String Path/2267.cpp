class Solution {
 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i][j][k] := 1 if there's a path from grid[i][j] to grid[m - 1][n - 1]
    // w/ # of '(' - # of ')' == k
    dp.resize(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
    return hasValidPath(grid, 0, 0, 0);
  }

 private:
  vector<vector<vector<int>>> dp;

  int hasValidPath(const vector<vector<char>>& grid, int i, int j, int k) {
    if (i == grid.size() || j == grid[0].size())
      return 0;
    k += grid[i][j] == '(' ? 1 : -1;
    if (k < 0)
      return 0;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return k == 0;
    if (dp[i][j][k] != -1)
      return dp[i][j][k];
    return dp[i][j][k] = hasValidPath(grid, i + 1, j, k) |
                         hasValidPath(grid, i, j + 1, k);
  }
};
