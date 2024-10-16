class Solution {
 public:
  int minimumObstacles(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    using T = tuple<int, int, int>;  // (d, i, j)
    priority_queue<T, vector<T>, greater<>> minHeap;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    minHeap.emplace(grid[0][0], 0, 0);
    dist[0][0] = grid[0][0];

    while (!minHeap.empty()) {
      const auto [d, i, j] = minHeap.top();
      minHeap.pop();
      if (i == m - 1 && j == n - 1)
        return d;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        const int newDist = d + grid[i][j];
        if (newDist < dist[x][y]) {
          dist[x][y] = newDist;
          minHeap.emplace(newDist, x, y);
        }
      }
    }

    return dist[m - 1][n - 1];
  }
};
