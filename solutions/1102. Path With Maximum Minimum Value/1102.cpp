struct T {
  int i;
  int j;
  int val;
};

class Solution {
 public:
  int maximumMinimumPath(vector<vector<int>>& grid) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = grid[0][0];
    vector<vector<bool>> seen(m, vector<bool>(n));
    auto compare = [](const T& a, const T& b) { return a.val < b.val; };
    priority_queue<T, vector<T>, decltype(compare)> maxHeap(compare);

    maxHeap.emplace(0, 0, grid[0][0]);

    while (!maxHeap.empty()) {
      const auto [i, j, val] = maxHeap.top();
      maxHeap.pop();
      ans = min(ans, val);
      if (i == m - 1 && j == n - 1)
        return ans;
      seen[i][j] = true;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        maxHeap.emplace(x, y, grid[x][y]);
      }
    }

    throw;
  }
};
