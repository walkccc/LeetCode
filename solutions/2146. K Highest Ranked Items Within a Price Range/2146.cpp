class Solution {
 public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                          vector<int>& pricing,
                                          vector<int>& start, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int low = pricing[0];
    const int high = pricing[1];
    const int row = start[0];
    const int col = start[1];
    const vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> ans;

    if (low <= grid[row][col] && grid[row][col] <= high) {
      ans.push_back({row, col});
      if (k == 1)
        return ans;
    }

    queue<pair<int, int>> q{{{row, col}}};
    vector<vector<bool>> seen(m, vector<bool>(n));
    seen[row][col] = true;  // Mark as visited.

    while (!q.empty()) {
      vector<vector<int>> neighbors;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (!grid[x][y] || seen[x][y])
            continue;
          if (low <= grid[x][y] && grid[x][y] <= high)
            neighbors.push_back({x, y});
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
      ranges::sort(neighbors, [&](const auto& a, const auto& b) {
        const int x1 = a[0];
        const int y1 = a[1];
        const int x2 = b[0];
        const int y2 = b[1];
        if (grid[x1][y1] != grid[x2][y2])
          return grid[x1][y1] < grid[x2][y2];
        return x1 == x2 ? y1 < y2 : x1 < x2;
      });
      for (const vector<int>& neighbor : neighbors) {
        if (ans.size() < k)
          ans.push_back(neighbor);
        if (ans.size() == k)
          return ans;
      }
    }

    return ans;
  }
};
