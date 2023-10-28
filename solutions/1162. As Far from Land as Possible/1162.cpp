class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    int water = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0)
          ++water;
        else
          q.emplace(i, j);

    if (water == 0 || water == m * n)
      return -1;

    int ans = 0;

    for (int d = 0; !q.empty(); ++d)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        ans = d;
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] > 0)
            continue;
          q.emplace(x, y);
          grid[x][y] = 2;  // Mark as visited.
        }
      }

    return ans;
  }
};
