class Solution {
 public:
  int shortestBridge(vector<vector<int>>& A) {
    const int n = A.size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = 0;
    queue<pair<int, int>> q;

    markAsTwo(A, q);

    // expand by BFS
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (A[x][y] == 2)
            continue;
          if (A[x][y] == 1)
            return ans;
          A[x][y] = 2;
          q.push({x, y});
        }
      }
      ++ans;
    }

    throw;
  }

 private:
  // mark one group to 2s by DFS
  void markAsTwo(vector<vector<int>>& A, queue<pair<int, int>>& q) {
    for (int i = 0; i < A.size(); ++i)
      for (int j = 0; j < A[0].size(); ++j)
        if (A[i][j] == 1) {
          markAsTwo(A, i, j, q);
          return;
        }
  }

  // mark one group to 2s by DFS and push them to the q
  void markAsTwo(vector<vector<int>>& A, int i, int j,
                 queue<pair<int, int>>& q) {
    if (i < 0 || i == A.size() || j < 0 || j == A[0].size())
      return;
    if (A[i][j] != 1)
      return;

    A[i][j] = 2;
    q.push({i, j});
    markAsTwo(A, i + 1, j, q);
    markAsTwo(A, i - 1, j, q);
    markAsTwo(A, i, j + 1, q);
    markAsTwo(A, i, j - 1, q);
  }
};
