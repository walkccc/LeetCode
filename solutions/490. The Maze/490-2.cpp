class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    return dfs(maze,
               vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size())),
               start[0], start[1], destination);
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool dfs(vector<vector<int>>& maze, vector<vector<bool>>&& seen, int i, int j,
           const vector<int>& destination) {
    if (i == destination[0] && j == destination[1])
      return true;
    if (seen[i][j])
      return false;

    seen[i][j] = true;

    for (const auto& [dx, dy] : dirs) {
      int x = i;
      int y = j;
      while (isValid(maze, x + dx, y + dy)) {
        x += dx;
        y += dy;
      }
      if (dfs(maze, std::move(seen), x, y, destination))
        return true;
    }

    return false;
  }

  bool isValid(const vector<vector<int>>& maze, int x, int y) {
    return 0 <= x && x < maze.size() && 0 <= y && y < maze[0].size() &&
           maze[x][y] == 0;
  }
};
