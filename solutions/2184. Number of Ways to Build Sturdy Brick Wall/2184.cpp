class Solution {
 public:
  int buildWall(int height, int width, vector<int>& bricks) {
    constexpr int kMod = 1'000'000'007;
    // Stores the valid rows in bitmask.
    vector<int> rows;
    buildRows(width, bricks, 0, rows);

    const int n = rows.size();
    // dp[i] := the number of ways to build `h` height walls with rows[i] in the
    // bottom
    vector<long> dp(n, 1);
    // graph[i] := the valid neighbors of rows[i]
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (!(rows[i] & rows[j]))
          graph[i].push_back(j);

    for (int h = 2; h <= height; ++h) {
      vector<long> newDp(n);
      for (int i = 0; i < n; ++i)
        for (const int v : graph[i]) {
          newDp[i] += dp[v];
          newDp[i] %= kMod;
        }
      dp = std::move(newDp);
    }

    return accumulate(dp.begin(), dp.end(), 0L) % kMod;
  }

 private:
  void buildRows(int width, const vector<int>& bricks, int path,
                 vector<int>& rows) {
    for (const int brick : bricks)
      if (brick == width)
        rows.push_back(path);
      else if (brick < width) {
        const int newWidth = width - brick;
        buildRows(newWidth, bricks, path | 1 << newWidth, rows);
      }
  }
};
