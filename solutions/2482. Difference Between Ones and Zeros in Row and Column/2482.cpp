class Solution {
 public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    vector<int> onesRow;
    vector<int> onesCol;

    for (const vector<int>& row : grid)
      onesRow.push_back(ranges::count(row, 1));

    for (int j = 0; j < n; ++j) {
      int ones = 0;
      for (int i = 0; i < m; ++i)
        ones += grid[i][j];
      onesCol.push_back(ones);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans[i][j] =
            onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);

    return ans;
  }
};
