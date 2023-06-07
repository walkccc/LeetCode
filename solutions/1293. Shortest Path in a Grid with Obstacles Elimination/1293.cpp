class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (m == 1 && n == 1)
      return 0;

    const vector<int> dirs{0, 1, 0, -1, 0};
    int steps = 0;
    queue<tuple<int, int, int>> q{{{0, 0, k}}};  // (i, j, eliminate)
    vector<vector<vector<bool>>> seen(
        m, vector<vector<bool>>(n, vector<bool>(k + 1)));
    seen[0][0][k] = true;

    while (!q.empty()) {
      ++steps;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j, eliminate] = q.front();
        q.pop();
        for (int l = 0; l < 4; ++l) {
          const int x = i + dirs[l];
          const int y = j + dirs[l + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (x == m - 1 && y == n - 1)
            return steps;
          if (grid[x][y] == 1 && eliminate == 0)
            continue;
          const int newEliminate = eliminate - grid[x][y];
          if (seen[x][y][newEliminate])
            continue;
          q.emplace(x, y, newEliminate);
          seen[x][y][newEliminate] = true;
        }
      }
    }

    return -1;
  }
};
