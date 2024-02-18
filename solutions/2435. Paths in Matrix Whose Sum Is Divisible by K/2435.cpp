class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    vector<vector<vector<int>>> mem(
        grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, -1)));
    return numberOfPaths(grid, 0, 0, 0, k, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of paths to (i, j), where the sum / k == `sum`.
  int numberOfPaths(const vector<vector<int>>& grid, int i, int j, int sum,
                    int k, vector<vector<vector<int>>>& mem) {
    if (i == grid.size() || j == grid[0].size())
      return 0;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return (sum + grid[i][j]) % k == 0;
    if (mem[i][j][sum] != -1)
      return mem[i][j][sum];
    const int newSum = (sum + grid[i][j]) % k;
    return mem[i][j][sum] = (numberOfPaths(grid, i + 1, j, newSum, k, mem) +
                             numberOfPaths(grid, i, j + 1, newSum, k, mem)) %
                            kMod;
  }
};
