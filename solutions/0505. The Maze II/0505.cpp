class Solution {
 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    const int m = maze.size();
    const int n = maze[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q{{{start[0], start[1]}}};
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[start[0]][start[1]] = 0;

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int x = i;
        int y = j;
        int steps = dist[i][j];
        while (isValid(maze, x + dirs[k], y + dirs[k + 1])) {
          x += dirs[k];
          y += dirs[k + 1];
          ++steps;
        }
        if (steps < dist[x][y]) {
          dist[x][y] = steps;
          if (x == destination[0] && y == destination[1])
            continue;
          q.emplace(x, y);
        }
      }
    }

    return dist[destination[0]][destination[1]] == INT_MAX
               ? -1
               : dist[destination[0]][destination[1]];
  }

 private:
  bool isValid(const vector<vector<int>>& maze, int x, int y) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() &&
           maze[x][y] == 0;
  }
};
