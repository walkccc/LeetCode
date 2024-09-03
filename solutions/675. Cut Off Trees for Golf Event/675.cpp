struct T {
  int i;
  int j;
  int height;
};

class Solution {
 public:
  int cutOffTree(vector<vector<int>>& forest) {
    auto compare = [&](const T& a, const T& b) { return a.height > b.height; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

    for (int i = 0; i < forest.size(); ++i)
      for (int j = 0; j < forest[0].size(); ++j)
        if (forest[i][j] > 1)
          minHeap.emplace(i, j, forest[i][j]);

    int ans = 0;
    int x = 0;
    int y = 0;

    while (!minHeap.empty()) {
      const auto [i, j, _] = minHeap.top();
      minHeap.pop();
      // Walk from (x, y) to (i, j).
      const int steps = bfs(forest, x, y, i, j);
      if (steps < 0)
        return -1;
      ans += steps;
      x = i;
      y = j;
    }

    return ans;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int bfs(const vector<vector<int>>& forest, int si, int sj, int ei, int ej) {
    const int m = forest.size();
    const int n = forest[0].size();
    int steps = 0;
    queue<pair<int, int>> q{{{si, sj}}};
    vector<vector<bool>> seen(m, vector<bool>(n));
    seen[si][sj] = true;

    while (!q.empty()) {
      for (int s = q.size(); s > 0; --s) {
        const auto [i, j] = q.front();
        q.pop();
        if (i == ei && j == ej)
          return steps;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || forest[x][y] == 0)
            continue;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
      ++steps;
    }

    return -1;
  };
};
