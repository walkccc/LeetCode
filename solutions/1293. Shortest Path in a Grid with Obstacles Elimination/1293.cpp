struct T {
  int i;
  int j;
  int r;  // remaining
  T(int i, int j, int r) : i(i), j(j), r(r) {}
};

class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (m == 1 && n == 1)
      return 0;

    const vector<int> dirs{0, 1, 0, -1, 0};

    int steps = 0;
    queue<T> q{{{0, 0, k}}};
    vector<vector<vector<bool>>> seen(
        m, vector<vector<bool>>(n, vector<bool>(k + 1)));
    seen[0][0][k] = true;

    while (!q.empty()) {
      ++steps;
      for (int size = q.size(); size > 0; --size) {
        const auto [i, j, r] = q.front();
        q.pop();
        for (int l = 0; l < 4; ++l) {
          const int x = i + dirs[l];
          const int y = j + dirs[l + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (x == m - 1 && y == n - 1)
            return steps;
          if (grid[x][y] == 1 && r == 0)
            continue;
          const int newR = r - grid[x][y];
          if (seen[x][y][newR])
            continue;
          q.emplace(x, y, newR);
          seen[x][y][r - newR] = true;
        }
      }
    }

    return -1;
  }
};
