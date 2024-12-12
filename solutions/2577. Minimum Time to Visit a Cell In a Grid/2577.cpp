class Solution {
 public:
  int minimumTime(vector<vector<int>>& grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1)
      return -1;

    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    using T = tuple<int, int, int>;  // (time, i, j)
    priority_queue<T, vector<T>, greater<>> minHeap;
    vector<vector<bool>> seen(m, vector<bool>(n));

    minHeap.emplace(0, 0, 0);
    seen[0][0] = true;

    while (!minHeap.empty()) {
      const auto [time, i, j] = minHeap.top();
      minHeap.pop();
      if (i == m - 1 && j == n - 1)
        return time;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        const int extraWait = (grid[x][y] - time) % 2 == 0 ? 1 : 0;
        const int nextTime = max(time + 1, grid[x][y] + extraWait);
        minHeap.emplace(nextTime, x, y);
        seen[x][y] = true;
      }
    }

    throw;
  }
};
