class Solution {
 public:
  int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    constexpr int kMax = 15;
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<vector<int>>> mem(
        m, vector<vector<int>>(n, vector<int>(kMax + 1, -1)));
    return count(grid, 0, 0, 0, k, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Return the number of paths from (i, j) to (m - 1, n - 1) with XOR value
  // `xors`.
  int count(const vector<vector<int>>& grid, int i, int j, int xors, int k,
            vector<vector<vector<int>>>& mem) {
    if (i == grid.size() || j == grid[0].size())
      return 0;
    xors ^= grid[i][j];
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return xors == k ? 1 : 0;
    if (mem[i][j][xors] != -1)
      return mem[i][j][xors];
    const int right = count(grid, i, j + 1, xors, k, mem) % kMod;
    const int down = count(grid, i + 1, j, xors, k, mem) % kMod;
    return mem[i][j][xors] = (right + down) % kMod;
  }
};
