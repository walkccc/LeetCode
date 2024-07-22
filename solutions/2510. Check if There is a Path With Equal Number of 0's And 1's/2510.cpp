class Solution {
 public:
  bool isThereAPath(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // Map negative (the number of 0s - the number of 1s) to non-negative one.
    const int cells = m + n - 1;
    if (cells % 2 == 1)
      return false;
    vector<vector<vector<int>>> mem(
        m, vector<vector<int>>(n, vector<int>(cells * 2 + 1, -1)));
    return isThereAPath(grid, 0, 0, 0, cells, mem);
  }

 private:
  // Returns 1 if there's a path to grid[i][j]
  // s.t. `sum` = (the number of 0s - the number of 1s).
  bool isThereAPath(const vector<vector<int>>& grid, int i, int j, int sum,
                    const int& cells, vector<vector<vector<int>>>& mem) {
    if (i == grid.size() || j == grid[0].size())
      return false;
    sum += grid[i][j] == 0 ? 1 : -1;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return sum == 0;
    const int k = cells + sum;
    if (mem[i][j][k] != -1)
      return mem[i][j][k];
    return mem[i][j][k] = isThereAPath(grid, i + 1, j, sum, cells, mem) ||
                          isThereAPath(grid, i, j + 1, sum, cells, mem);
  }
};
