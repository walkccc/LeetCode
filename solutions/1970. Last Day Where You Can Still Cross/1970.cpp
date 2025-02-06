class Solution {
 public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int ans = 0;
    int l = 1;
    int r = cells.size() - 1;

    while (l <= r) {
      const int m = (l + r) / 2;
      if (canWalk(m, row, col, cells)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool canWalk(int day, int row, int col, const vector<vector<int>>& cells) {
    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < day; ++i) {
      const int x = cells[i][0] - 1;
      const int y = cells[i][1] - 1;
      matrix[x][y] = 1;
    }

    queue<pair<int, int>> q;

    for (int j = 0; j < col; ++j)
      if (matrix[0][j] == 0) {
        q.emplace(0, j);
        matrix[0][j] = 1;
      }

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == row || y < 0 || y == col)
          continue;
        if (matrix[x][y] == 1)
          continue;
        if (x == row - 1)
          return true;
        q.emplace(x, y);
        matrix[x][y] = 1;
      }
    }

    return false;
  }
};
