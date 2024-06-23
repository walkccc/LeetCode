class Solution {
 public:
  int maxStudents(vector<vector<char>>& seats) {
    return accumulate(
               seats.begin(), seats.end(), 0,
               [&](int a, const auto& seat) {
      return a + ranges::count(seat, '.');
               }) -
        hungarian(seats);
  }

 private:
  const vector<pair<int, int>> dirs{{-1, -1}, {0, -1}, {1, -1},
                                    {-1, 1},  {0, 1},  {1, 1}};

  int hungarian(const vector<vector<char>>& seats) {
    const int m = seats.size();
    const int n = seats[0].size();
    int count = 0;
    vector<vector<int>> seen(m, vector<int>(n));
    vector<vector<int>> match(m, vector<int>(n, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seats[i][j] == '.' && match[i][j] == -1) {
          const int sessionId = i * n + j;
          seen[i][j] = sessionId;
          count += dfs(seats, i, j, sessionId, seen, match);
        }

    return count;
  }

  int dfs(const vector<vector<char>>& seats, int i, int j, int sessionId,
          vector<vector<int>>& seen, vector<vector<int>>& match) {
    const int m = seats.size();
    const int n = seats[0].size();

    for (const auto& [dx, dy] : dirs) {
      const int x = i + dx;
      const int y = j + dy;
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (seats[x][y] != '.' || seen[x][y] == sessionId)
        continue;
      seen[x][y] = sessionId;
      if (match[x][y] == -1 || dfs(seats, match[x][y] / n, match[x][y] % n,
                                   sessionId, seen, match)) {
        match[x][y] = i * n + j;
        match[i][j] = x * n + y;
        return 1;
      }
    }

    return 0;
  }
};
