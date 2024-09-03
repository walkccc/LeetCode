struct T {
  int i;
  int j;
  int keys;  // the keys in the bitmask
};

class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].length();
    const int keysCount = getKeysCount(grid);
    const int kKeys = (1 << keysCount) - 1;
    const vector<int> start = getStart(grid);
    int ans = 0;
    queue<T> q{{{start[0], start[1], 0}}};
    vector<vector<vector<bool>>> seen(
        m, vector<vector<bool>>(n, vector<bool>(kKeys)));
    seen[start[0]][start[1]][0] = true;

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j, keys] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          const char c = grid[x][y];
          if (c == '#')
            continue;
          const int newKeys = 'a' <= c && c <= 'f' ? keys | 1 << c - 'a' : keys;
          if (newKeys == kKeys)
            return ans;
          if (seen[x][y][newKeys])
            continue;
          if ('A' <= c && c <= 'F' && (newKeys >> c - 'A' & 1) == 0)
            continue;
          q.emplace(x, y, newKeys);
          seen[x][y][newKeys] = true;
        }
      }
    }

    return -1;
  }

 private:
  int getKeysCount(const vector<string>& grid) {
    int count = 0;
    for (const string& s : grid)
      count += ranges::count_if(s, [](char c) { return 'a' <= c && c <= 'f'; });
    return count;
  }

  vector<int> getStart(const vector<string>& grid) {
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].length(); ++j)
        if (grid[i][j] == '@')
          return {i, j};
    throw;
  }
};
