class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    const int n = board.size();
    queue<int> q{{1}};
    vector<bool> seen(1 + n * n);
    vector<int> A(1 + n * n);  // 2D -> 1D

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        A[(n - 1 - i) * n + ((n - i) % 2 == 0 ? n - j : j + 1)] = board[i][j];

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const int curr = q.front();
        q.pop();
        for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
          const int dest = A[next] > 0 ? A[next] : next;
          if (dest == n * n)
            return step;
          if (seen[dest])
            continue;
          q.push(dest);
          seen[dest] = true;
        }
      }

    return -1;
  }
};
