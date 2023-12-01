class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    m = grid.size();
    n = grid[0].size();
    // dp[i][j][sum] : = the number of paths to(i, j), where the sum / k == sum
    dp.resize(m, vector<vector<int>>(n, vector<int>(k, -1)));
    return numberOfPaths(grid, 0, 0, 0, k);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  int m;
  int n;
  vector<vector<vector<int>>> dp;

  int numberOfPaths(const vector<vector<int>>& grid, int i, int j, int sum,
                    int k) {
    if (i == m || j == n)
      return 0;
    if (i == m - 1 && j == n - 1)
      return (sum + grid[i][j]) % k == 0;
    if (dp[i][j][sum] != -1)
      return dp[i][j][sum];
    const int newSum = (sum + grid[i][j]) % k;
    return dp[i][j][sum] = (numberOfPaths(grid, i + 1, j, newSum, k) +
                            numberOfPaths(grid, i, j + 1, newSum, k)) %
                           kMod;
  }
};
