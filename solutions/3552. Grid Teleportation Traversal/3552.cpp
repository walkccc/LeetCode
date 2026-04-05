class Solution {
 public:
  // Similar to 3341. Find Minimum Time to Reach Last Room I
  int minMoves(vector<string>& matrix) {
    if (matrix.back().back() == '#')
      return -1;

    vector<vector<pair<int, int>>> teleportPositions(26);

    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j)
        if (matrix[i][j] != '.' && matrix[i][j] != '#')
          teleportPositions[matrix[i][j] - 'A'].emplace_back(i, j);

    return dijkstra(matrix, teleportPositions, {0, 0},
                    {matrix.size() - 1, matrix[0].size() - 1});
  }

 private:
  int dijkstra(const vector<string>& matrix,
               const vector<vector<pair<int, int>>>& teleportPositions,
               const pair<int, int>& src, const pair<int, int>& dst) {
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    vector<bool> seen(26);

    dist[0][0] = 0;
    using T = pair<int, pair<int, int>>;  // (d, u)
    priority_queue<T, vector<T>, greater<>> minHeap;
    minHeap.push({dist[0][0], src});

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (u == dst)
        return d;
      const auto [i, j] = u;
      if (d > dist[i][j])
        continue;
      const char c = matrix[i][j];
      if (isupper(c) && !seen[c - 'A']) {
        seen[c - 'A'] = true;
        for (const auto& [x, y] : teleportPositions[c - 'A'])
          if (d < dist[x][y]) {
            dist[x][y] = d;
            minHeap.push({d, {x, y}});
          }
      }
      for (const auto& [dx, dy] : kDirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (matrix[x][y] == '#')
          continue;
        if (d + 1 < dist[x][y]) {
          dist[x][y] = d + 1;
          minHeap.push({d + 1, {x, y}});
        }
      }
    }

    return -1;
  }
};
