class Solution {
 public:
  int numOfArrays(int n, int m, int k) {
    constexpr int kMod = 1'000'000'007;
    // dp[i][j][k] := the number of ways to build an array of length i, where j
    // is the maximum number and k is the `search_cost`
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));
    // prefix[i][j][k] := sum(dp[i][x][k]), where 1 <= x <= j
    vector<vector<vector<int>>> prefix(
        n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));

    for (int j = 1; j <= m; ++j) {
      dp[1][j][1] = 1;
      prefix[1][j][1] = j;
    }

    for (int i = 2; i <= n; ++i)                 // for each length
      for (int j = 1; j <= m; ++j)               // for each max value
        for (int cost = 1; cost <= k; ++cost) {  // for each cost
          // 1. Appending any of [1, j] in the i-th position doesn't change the
          //    maximum and cost.
          // 2. Appending j in the i-th position makes j the new max and
          //    cost 1.
          dp[i][j][cost] = (static_cast<long>(j) * dp[i - 1][j][cost] +
                            prefix[i - 1][j - 1][cost - 1]) %
                           kMod;
          prefix[i][j][cost] = (dp[i][j][cost] + prefix[i][j - 1][cost]) % kMod;
        }

    int ans = 0;
    for (int j = 1; j <= m; ++j) {
      ans += dp[n][j][k];
      ans %= kMod;
    }
    return ans;
  }
};
