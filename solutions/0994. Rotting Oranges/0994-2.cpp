class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;
    int countFresh = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          ++countFresh;
        else if (grid[i][j] == 2)
          q.emplace(i, j);

    if (countFresh == 0)
      return 0;

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] != 1)
            continue;
          grid[x][y] = 2;   // Mark grid[x][y] as rotten.
          q.emplace(x, y);  // Push the newly rotten orange to the queue.
          --countFresh;     // Decrease the count of fresh oranges by 1.
        }
      }
    }

    return countFresh == 0 ? ans - 1 : -1;
  }
};
