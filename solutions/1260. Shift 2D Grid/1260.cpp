class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    k %= m * n;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int index = (i * n + j + k) % (m * n);
        int x = index / n;
        int y = index % n;
        ans[x][y] = grid[i][j];
      }

    return ans;
  }
};
