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
    island.push_back({i, j});

    dfs(grid, i + 1, j, seen, island);
    dfs(grid, i - 1, j, seen, island);
    dfs(grid, i, j + 1, seen, island);
    dfs(grid, i, j - 1, seen, island);
  }

  vector<pair<int, int>> normalize(const vector<pair<int, int>>& island) {
    // points[i] := 8 different rotations/reflections of island
    vector<vector<pair<int, int>>> points(8);

    for (const auto [i, j] : island) {
      points[0].push_back({i, j});
      points[1].push_back({i, -j});
      points[2].push_back({-i, j});
      points[3].push_back({-i, -j});
      points[4].push_back({j, i});
      points[5].push_back({j, -i});
      points[6].push_back({-j, i});
      points[7].push_back({-j, -i});
    }

    for (vector<pair<int, int>>& point : points)
      sort(begin(point), end(point));

    // normalize each point by minus point[1:] w/ point[0]
    for (vector<pair<int, int>>& point : points) {
      for (int i = 1; i < island.size(); ++i)
        point[i] = {point[i].first - point[0].first,
                    point[i].second - point[0].second};
      point[0] = {0, 0};
    }

    sort(begin(points), end(points));
    return points[0];
  }
};
