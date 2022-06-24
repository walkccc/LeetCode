class Solution {
 public:
  int numDistinctIslands2(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    set<vector<pair<int, int>>> islands;  // all different shape islands
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        vector<pair<int, int>> island;
        dfs(grid, i, j, seen, island);
        if (!island.empty())
          islands.insert(normalize(island));
      }

    return islands.size();
  }

 private:
  void dfs(const vector<vector<int>>& grid, int i, int j,
           vector<vector<bool>>& seen, vector<pair<int, int>>& island) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] == 0 || seen[i][j])
      return;

    seen[i][j] = true;
    island.emplace_back(i, j);

    dfs(grid, i + 1, j, seen, island);
    dfs(grid, i - 1, j, seen, island);
    dfs(grid, i, j + 1, seen, island);
    dfs(grid, i, j - 1, seen, island);
  }

  vector<pair<int, int>> normalize(const vector<pair<int, int>>& island) {
    // points[i] := 8 different rotations/reflections of island
    vector<vector<pair<int, int>>> points(8);

    for (const auto& [i, j] : island) {
      points[0].emplace_back(i, j);
      points[1].emplace_back(i, -j);
      points[2].emplace_back(-i, j);
      points[3].emplace_back(-i, -j);
      points[4].emplace_back(j, i);
      points[5].emplace_back(j, -i);
      points[6].emplace_back(-j, i);
      points[7].emplace_back(-j, -i);
    }

    for (vector<pair<int, int>>& p : points)
      sort(begin(p), end(p));

    // normalize each p by minus p[1:] w/ p[0]
    for (vector<pair<int, int>>& p : points) {
      for (int i = 1; i < island.size(); ++i)
        p[i] = {p[i].first - p[0].first, p[i].second - p[0].second};
      p[0] = {0, 0};
    }

    sort(begin(points), end(points));
    return points[0];
  }
};
