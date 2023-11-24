class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    const int m = maze.size();
    const int n = maze[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;
    queue<pair<int, int>> q{{{entrance[0], entrance[1]}}};
    vector<vector<bool>> seen(m, vector<bool>(n));
    seen[entrance[0]][entrance[1]] = true;

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || maze[x][y] == '+')
            continue;
          if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
            return ans;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
    }

    return -1;
  }
};
