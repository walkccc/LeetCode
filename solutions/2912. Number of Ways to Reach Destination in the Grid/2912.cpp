class Solution {
 public:
  int numberOfWays(int n, int m, int k, vector<int>& source,
                   vector<int>& dest) {
    constexpr int kMod = 1'000'000'007;
    // dp[i][0] := the the number of ways of `source` to `dest` using i
    // steps dp[i][1] := the the number of ways of `source` to dest's row
    // using i steps dp[i][2] := the the number of ways of `source` to
    // dest's col using i steps dp[i][3] := the the number of ways of
    // `source` to others using i steps
    vector<vector<int>> dp(k + 1, vector<int>(4));
    if (source == dest)
      dp[0][0] = 1;
    else if (source[0] == dest[0])
      dp[0][1] = 1;
    else if (source[1] == dest[1])
      dp[0][2] = 1;
    else
      dp[0][3] = 1;

    for (int i = 1; i <= k; i++) {
      dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % kMod;
      dp[i][1] = ((dp[i - 1][0] * (m - 1L) +  // -self
                   dp[i - 1][1] * (m - 2L) +  // -self, -center
                   dp[i - 1][3]) %
                  kMod);
      dp[i][2] = ((dp[i - 1][0] * (n - 1L) +  // -self
                   dp[i - 1][2] * (n - 2L) +  // -self, -center
                   dp[i - 1][3]) %
                  kMod);
      dp[i][3] = ((dp[i - 1][1] * (n - 1L) +         // -self
                   dp[i - 1][2] * (m - 1L) +         // -self
                   dp[i - 1][3] * (m + n - 1 - 3L))  // -self, -row, -col
                  % kMod);
    }

    return dp[k][0];
  }
};
