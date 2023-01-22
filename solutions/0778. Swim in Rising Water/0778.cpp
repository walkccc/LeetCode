class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = grid[0][0];
    using T = tuple<int, int, int>;  // (grid[i][j], i, j)
    priority_queue<T, vector<T>, greater<>> minHeap;
    vector<vector<bool>> seen(n, vector<bool>(n));

    minHeap.emplace(grid[0][0], 0, 0);
    seen[0][0] = true;

    while (!minHeap.empty()) {
      const auto [height, i, j] = minHeap.top();
      minHeap.pop();
      ans = max(ans, height);
      if (i == n - 1 && j == n - 1)
        break;
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == n || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        minHeap.emplace(grid[x][y], x, y);
        seen[x][y] = true;
      }
    }

    return ans;
  }
};
