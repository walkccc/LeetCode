/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *  public:
 *   bool canMove(char direction);
 *   void std::move(char direction);
 *   boolean isTarget();
 * };
 */

enum class Grid { kUnvisited, kStart, kTarget, kBlocked, kEmpty };

class Solution {
 public:
  int findShortestPath(GridMaster& master) {
    constexpr int m = 500;
    constexpr int startX = m;
    constexpr int startY = m;
    vector<vector<Grid>> grid(m * 2, vector<Grid>(m * 2, Grid::kUnvisited));

    // Build the grid information by DFS.
    dfs(master, grid, startX, startY);

    int ans = 0;
    queue<pair<int, int>> q{{{startX, startY}}};
    grid[startX][startY] = Grid::kBlocked;

    // Find the steps by BFS.
    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (grid[x][y] == Grid::kTarget)
            return ans;
          if (grid[x][y] == Grid::kBlocked)
            continue;
          grid[x][y] = Grid::kBlocked;
          q.emplace(x, y);
        }
      }
    }

    return -1;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  static constexpr char charTable[4] = {'R', 'D', 'L', 'U'};

  void dfs(GridMaster& master, vector<vector<Grid>>& grid, int i, int j) {
    if (grid[i][j] != Grid::kUnvisited)
      return;
    if (master.isTarget())
      grid[i][j] = Grid::kTarget;
    else
      grid[i][j] = Grid::kEmpty;

    for (int k = 0; k < 4; ++k) {
      const int x = i + dirs[k][0];
      const int y = j + dirs[k][1];
      const char d = charTable[k];
      const char undoD = charTable[(k + 2) % 4];
      if (master.canMove(d)) {
        master.std::move(d);
        dfs(master, grid, x, y);
        master.std::move(undoD);
      } else {
        grid[x][y] = Grid::kBlocked;
      }
    }
  }
};
