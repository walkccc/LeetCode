class Solution {
 public:
  int minFlips(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int rowFlips = 0;
    int colFlips = 0;

    for (const vector<int>& row : grid)
      for (int i = 0; i < n / 2; ++i)
        if (row[i] != row[n - 1 - i])
          ++rowFlips;

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m / 2; ++i)
        if (grid[i][j] != grid[m - 1 - i][j])
          ++colFlips;

    return min(rowFlips, colFlips);
  }
};
