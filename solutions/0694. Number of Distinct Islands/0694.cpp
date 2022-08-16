class Solution {
 public:
  int numDistinctIslands(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    set<vector<pair<int, int>>> islands;  // all different islands
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        vector<pair<int, int>> island;
        dfs(grid, i, j, i, j, seen, island);
        if (!island.empty())
          islands.insert(island);
      }

    return islands.size();
  }

 private:
  void dfs(const vector<vector<int>>& grid, int i, int j, int i0, int j0,
           vector<vector<bool>>& seen, vector<pair<int, int>>& island) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] == 0 || seen[i][j])
      return;

    seen[i][j] = true;
    island.emplace_back(i - i0, j - j0);

    dfs(grid, i + 1, j, i0, j0, seen, island);
    dfs(grid, i - 1, j, i0, j0, seen, island);
    dfs(grid, i, j + 1, i0, j0, seen, island);
    dfs(grid, i, j - 1, i0, j0, seen, island);
  }
};
