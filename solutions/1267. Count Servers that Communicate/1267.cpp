class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
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
        if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1))
          ++ans;

    return ans;
  }
};
