struct T {
  int i;
  int j;
  int d;  // the maximum difference of (i, j) and its neighbors
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = heights.size();
    const int n = heights[0].size();
    auto compare = [](const T& a, const T& b) { return a.d > b.d; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    // diff[i][j] := the maximum absolute difference to reach (i, j)
    vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> seen(m, vector<bool>(n));

    minHeap.emplace(0, 0, 0);
    diff[0][0] = 0;

    while (!minHeap.empty()) {
      const auto [i, j, d] = minHeap.top();
      minHeap.pop();
      if (i == m - 1 && j == n - 1)
        return d;
      seen[i][j] = true;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        const int newDiff = abs(heights[i][j] - heights[x][y]);
        const int maxDiff = max(diff[i][j], newDiff);
        if (diff[x][y] > maxDiff) {
          diff[x][y] = maxDiff;
          minHeap.emplace(x, y, maxDiff);
        }
      }
    }

    throw;
  }
};
