class Solution {
 public:
  int shortestBridge(vector<vector<int>>& A) {
    const int n = A.size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = 0;
    queue<pair<int, int>> q;

    // mark one group to 2s (visited) by DFS and push them to the queue
    function<void(int, int)> markAsTwo = [&](int i, int j) {
      if (i < 0 || i == n || j < 0 || j == n) return;
      if (A[i][j] != 1) return;

      A[i][j] = 2;
      q.push({i, j});
      markAsTwo(i + 1, j);
      markAsTwo(i - 1, j);
      markAsTwo(i, j + 1);
      markAsTwo(i, j - 1);
    };

    [&]() {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (A[i][j] == 1) {
            markAsTwo(i, j);
            return;
          }
    }();

    // expand by BFS
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        const auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == n || y < 0 || y == n) continue;
          if (A[x][y] == 2) continue;
          if (A[x][y] == 1) return ans;
          A[x][y] = 2;
          q.push({x, y});
        }
      }
      ++ans;
    }

    throw;
  }
};