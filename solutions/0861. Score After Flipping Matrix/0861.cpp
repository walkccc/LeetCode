class Solution {
 public:
  int matrixScore(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;

    // flip rows with leading 0
    for (auto& row : grid)
      if (row[0] == 0)
        flip(row);

    // flip cols with 1s < 0s
    for (int j = 0; j < n; ++j)
      if (onesColCount(grid, j) * 2 < m)
        flipCol(grid, j);

    // add binary number for each row
    for (const auto& row : grid)
      ans += binary(row);

    return ans;
  }

 private:
  void flip(vector<int>& row) {
    for (int i = 0; i < row.size(); ++i)
      row[i] ^= 1;
  }

  int onesColCount(const vector<vector<int>>& grid, int j) {
    int ones = 0;
    for (int i = 0; i < grid.size(); ++i)
      ones += grid[i][j];
    return ones;
  }

  void flipCol(vector<vector<int>>& grid, int j) {
    for (int i = 0; i < grid.size(); ++i)
      grid[i][j] ^= 1;
  }

  int binary(const vector<int>& row) {
    int res = row[0];
    for (int j = 1; j < row.size(); ++j)
      res = res * 2 + row[j];
    return res;
  }
};
