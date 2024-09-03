class Solution {
 public:
  long long numberOfRightTriangles(vector<vector<int>>& grid) {
    long count = 0;
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> rows(m);
    vector<int> cols(n);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          ++rows[i];
          ++cols[j];
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          count += (rows[i] - 1) * (cols[j] - 1);

    return count;
  }
};
