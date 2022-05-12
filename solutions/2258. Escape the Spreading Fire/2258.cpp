class Solution {
 public:
  int maximumMinutes(vector<vector<int>>& grid) {
    const vector<int> dirs{0, 1, 0, -1, 0};
    const int kMax = grid.size() * grid[0].size();
    vector<vector<int>> fireMinute(grid.size(),
                                   vector<int>(grid[0].size(), -1));
    buildFireGrid(grid, fireMinute, dirs);

    int ans = -1;
    int l = 0;
    int r = kMax;

    while (l <= r) {
      const int m = (l + r) / 2;
      if (canStayFor(grid, fireMinute, m, dirs)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans == kMax ? 1e9 : ans;
  }

 private:
  void buildFireGrid(const vector<vector<int>>& grid,
                     vector<vector<int>>& fireMinute, const vector<int>& dirs) {
    int minuteFromFire = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {  // fire
          q.emplace(i, j);
          fireMinute[i][j] = 0;
        }

    while (!q.empty()) {
      ++minuteFromFire;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
            continue;
          if (grid[x][y] == 2)  // wall
            continue;
          if (fireMinute[x][y] != -1)
            continue;
          fireMinute[x][y] = minuteFromFire;
          q.emplace(x, y);
        }
      }
    }
  }

  bool canStayFor(const vector<vector<int>>& grid,
                  const vector<vector<int>>& fireMinute, int minute,
                  const vector<int>& dirs) {
    queue<pair<int, int>> q{{{0, 0}}};  // start position
    vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
    seen[0][0] = true;

    while (!q.empty()) {
      ++minute;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
            continue;
          if (grid[x][y] == 2)  // wall
            continue;
          if (x == grid.size() - 1 && y == grid[0].size() - 1) {
            if (fireMinute[x][y] != -1 && fireMinute[x][y] < minute)
              continue;
            return true;
          }
          if (fireMinute[x][y] != -1 && fireMinute[x][y] <= minute)
            continue;
          if (seen[x][y])
            continue;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
    }

    return false;
  }
};
