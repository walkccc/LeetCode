class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = maze.size();
    const int n = maze[0].size();
    queue<pair<int, int>> q{{{entrance[0], entrance[1]}}};
    vector<vector<bool>> seen(m, vector<bool>(n));
    seen[entrance[0]][entrance[1]] = true;

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : kDirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || maze[x][y] == '+')
            continue;
          if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
            return step;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }

    return -1;
  }
};
