class Solution {
 public:
  long long sumRemoteness(vector<vector<int>>& grid) {
    const long sum = accumulate(grid.begin(), grid.end(), 0L,
                                [](long subtotal, const vector<int>& row) {
      return subtotal + accumulate(row.begin(), row.end(), 0L,
                                   [](long subtotal, const int cell) {
        return subtotal + max(0, cell);
      });
    });

    long ans = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] > 0) {
          const auto [count, componentSum] = dfs(grid, i, j);
          ans += (sum - componentSum) * count;
        }

    return ans;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // Returns the (count, componentSum) of the connected component that contains
  // (x, y).
  pair<int, long> dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return {0, 0};
    if (grid[i][j] == -1)
      return {0, 0};

    int count = 1;
    long componentSum = grid[i][j];
    grid[i][j] = -1;  // Mark as visited.;

    for (const auto& [dx, dy] : dirs) {
      const int x = i + dx;
      const int y = j + dy;
      const auto [nextCount, nextComponentSum] = dfs(grid, x, y);
      count += nextCount;
      componentSum += nextComponentSum;
    }

    return {count, componentSum};
  }
};
