class Solution {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        prefix[i + 1][j + 1] =
            grid[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        if (prefix[i + 1][j + 1] <= k)
          ++ans;
      }

    return ans;
  }
};
