class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    const int m = grid.size();
    const int n = grid[0].size();

    function<void(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (grid[i][j] != '1') return;

      grid[i][j] = '2';  // mark '2' as visited
      dfs(i + 1, j);
      dfs(i - 1, j);
      dfs(i, j + 1);
      dfs(i, j - 1);
    };

    int ans = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '1') {
          dfs(i, j);
          ++ans;
        }

    return ans;
  }
};