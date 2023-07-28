class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    const int m = maze.size();
    const int n = maze[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q{{{start[0], start[1]}}};
    vector<vector<bool>> seen(m, vector<bool>(n));
    seen[start[0]][start[1]] = true;

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int x = i;
        int y = j;
        while (isValid(maze, x + dirs[k], y + dirs[k + 1])) {
          x += dirs[k];
          y += dirs[k + 1];
        }
        if (x == destination[0] && y == destination[1])
          return true;
        if (seen[x][y])
          continue;
        q.emplace(x, y);
        seen[x][y] = true;
      }
    }

    return false;
  }

 private:
  bool isValid(const vector<vector<int>>& maze, int x, int y) {
    return 0 <= x && x < maze.size() && 0 <= y && y < maze[0].size() &&
           maze[x][y] == 0;
  }
};
