class Solution {
 public:
  int knightDialer(int n) {
    constexpr int kMod = 1'000'000'007;
    const vector<pair<int, int>> dirs = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                         {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    // dp[i][j] := the number of ways to stand on (i, j)
    vector<vector<int>> dp(4, vector<int>(3, 1));
    dp[3][0] = dp[3][2] = 0;

    for (int k = 0; k < n - 1; ++k) {
      vector<vector<int>> newDp(4, vector<int>(3));
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j) {
          if (isNotNumericCell(i, j))
            continue;
          for (const auto& [dx, dy] : dirs) {
            const int x = i + dx;
            const int y = j + dy;
            if (x < 0 || x >= 4 || y < 0 || y >= 3)
              continue;
            if (isNotNumericCell(x, y))
              continue;
            newDp[i][j] = (newDp[i][j] + dp[x][y]) % kMod;
          }
        }
      dp = move(newDp);
    }

    int ans = 0;

    for (const vector<int>& row : dp)
      for (const int a : row)
        ans = (ans + a) % kMod;

    return ans;
  }

 private:
  bool isNotNumericCell(int i, int j) {
    return i == 3 && (j == 0 || j == 2);
  }
};
