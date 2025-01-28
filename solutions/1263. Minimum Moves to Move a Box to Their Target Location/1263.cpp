class Solution {
 public:
  int minPushBox(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> box;
    vector<int> player;
    vector<int> target;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 'B')
          box = {i, j};
        else if (grid[i][j] == 'S')
          player = {i, j};
        else if (grid[i][j] == 'T')
          target = {i, j};

    // (boxX, boxY, playerX, playerY)
    queue<tuple<int, int, int, int>> q{
        {{box[0], box[1], player[0], player[1]}}};
    vector<vector<vector<vector<bool>>>> seen(
        m, vector<vector<vector<bool>>>(
               n, vector<vector<bool>>(m, vector<bool>(n))));
    seen[box[0]][box[1]][player[0]][player[1]] = true;

    for (int step = 0; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [boxX, boxY, playerX, playerY] = q.front();
        q.pop();
        if (boxX == target[0] && boxY == target[1])
          return step;
        for (int k = 0; k < 4; ++k) {
          const int nextBoxX = boxX + dirs[k % 4][0];
          const int nextBoxY = boxY + dirs[k % 4][1];
          if (isInvalid(grid, nextBoxX, nextBoxY))
            continue;
          if (seen[nextBoxX][nextBoxY][boxX][boxY])
            continue;
          const int fromX = boxX + dirs[(k + 2) % 4][0];
          const int fromY = boxY + dirs[(k + 2) % 4][1];
          if (isInvalid(grid, fromX, fromY))
            continue;
          if (canGoTo(grid, playerX, playerY, fromX, fromY, boxX, boxY)) {
            seen[nextBoxX][nextBoxY][boxX][boxY] = true;
            q.emplace(nextBoxX, nextBoxY, boxX, boxY);
          }
        }
      }

    return -1;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // Returns true if (playerX, playerY) can go to (fromX, fromY).
  bool canGoTo(const vector<vector<char>>& grid, int playerX, int playerY,
               int fromX, int fromY, int boxX, int boxY) {
    queue<pair<int, int>> q{{{playerX, playerY}}};
    vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
    seen[playerX][playerY] = true;

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      if (i == fromX && j == fromY)
        return true;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (isInvalid(grid, x, y))
          continue;
        if (seen[x][y])
          continue;
        if (x == boxX && y == boxY)
          continue;
        q.emplace(x, y);
        seen[x][y] = true;
      }
    }

    return false;
  }

  bool isInvalid(const vector<vector<char>>& grid, int playerX, int playerY) {
    return playerX < 0 || playerX == grid.size() || playerY < 0 ||
           playerY == grid[0].size() || grid[playerX][playerY] == '#';
  }
};
