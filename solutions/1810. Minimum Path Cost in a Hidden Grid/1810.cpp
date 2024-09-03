/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *  public:
 *   bool canMove(char direction);
 *   int std::move(char direction);
 *   boolean isTarget();
 * };
 */

class Solution {
 public:
  int findShortestPath(GridMaster& master) {
    constexpr int m = 100;
    constexpr int startX = m;
    constexpr int startY = m;

    vector<int> target{m * 2, m * 2};
    vector<vector<int>> grid(m * 2, vector<int>(m * 2, -1));
    vector<vector<bool>> seen(m * 2, vector<bool>(m * 2));

    // Build the grid information by DFS.
    dfs(master, grid, startX, startY, target);

    priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
    minHeap.push({0, startX, startY});

    // Find the steps by BFS.
    while (!minHeap.empty()) {
      const vector<int> tuple = minHeap.top();
      const int cost = tuple[0];
      const int i = tuple[1];
      const int j = tuple[2];
      minHeap.pop();
      if (i == target[0] && j == target[1])
        return cost;
      if (seen[i][j])
        continue;
      seen[i][j] = true;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == 2 * m || y < 0 || y == 2 * m)
          continue;
        if (seen[x][y] || grid[x][y] == -1)
          continue;
        const int nextCost = cost + grid[x][y];
        minHeap.push({nextCost, x, y});
      }
    }

    return -1;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  static constexpr char charTable[4] = {'R', 'D', 'L', 'U'};

  void dfs(GridMaster& master, vector<vector<int>>& grid, int i, int j,
           vector<int>& target) {
    if (master.isTarget()) {
      target[0] = i;
      target[1] = j;
    }

    for (int k = 0; k < 4; ++k) {
      const int x = i + dirs[k][0];
      const int y = j + dirs[k][1];
      const char d = charTable[k];
      const char undoD = charTable[(k + 2) % 4];
      if (master.canMove(d) && grid[x][y] == -1) {
        grid[x][y] = master.std::move(d);
        dfs(master, grid, x, y, target);
        master.std::move(undoD);
      }
    }
  }
};
