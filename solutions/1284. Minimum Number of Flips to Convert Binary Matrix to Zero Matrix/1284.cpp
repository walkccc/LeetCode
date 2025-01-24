class Solution {
 public:
  int minFlips(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    const int hash = getHash(mat, m, n);
    if (hash == 0)
      return 0;

    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<int> q{{hash}};
    unordered_set<int> seen{hash};

    for (int step = 1; !q.empty(); ++step) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int curr = q.front();
        q.pop();
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            int next = curr ^ 1 << (i * n + j);
            // Flie the four neighbors.
            for (const auto& [dx, dy] : dirs) {
              const int x = i + dx;
              const int y = j + dy;
              if (x < 0 || x == m || y < 0 || y == n)
                continue;
              next ^= 1 << (x * n + y);
            }
            if (next == 0)
              return step;
            if (seen.contains(next))
              continue;
            q.push(next);
            seen.insert(next);
          }
        }
      }
    }

    return -1;
  }

 private:
  int getHash(const vector<vector<int>>& mat, int m, int n) {
    int hash = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j])
          hash |= 1 << (i * n + j);
    return hash;
  }
};
