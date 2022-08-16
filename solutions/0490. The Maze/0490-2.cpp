class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    return dfs(maze,
               vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size())),
               start[0], start[1], destination);
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};

  bool dfs(vector<vector<int>>& maze, vector<vector<bool>>&& seen, int i, int j,
           const vector<int>& destination) {
    if (i == destination[0] && j == destination[1])
      return true;
    if (seen[i][j])
      return false;

    seen[i][j] = true;

    for (int k = 0; k < 4; ++k) {
      int x = i;
      int y = j;
      while (isValid(maze, x + dirs[k], y + dirs[k + 1])) {
        x += dirs[k];
        y += dirs[k + 1];
      }
      if (dfs(maze, move(seen), x, y, destination))
        return true;
    }

    return false;
  }

  bool isValid(const vector<vector<int>>& maze, int x, int y) {
    return 0 <= x && x < maze.size() && 0 <= y && y < maze[0].size() &&
           maze[x][y] == 0;
  }
};
