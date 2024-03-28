class Solution {
 public:
  int checkRecord(int n) {
    constexpr int kMod = 1'000'000'007;
    // dp[i][j] := the length so far with i A's and the last letters are j L's
    vector<vector<long>> dp(2, vector<long>(3));
    dp[0][0] = 1;

    while (n--) {
      const auto prev(dp);

      // Append a P.
      dp[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % kMod;

      // Append an L.
      dp[0][1] = prev[0][0];

      // Append an L.
      dp[0][2] = prev[0][1];

      // Append an A or append a P.
      dp[1][0] = (prev[0][0] + prev[0][1] + prev[0][2] +  //
                  prev[1][0] + prev[1][1] + prev[1][2]) %
                 kMod;

      // Append an L.
      dp[1][1] = prev[1][0];

      // Append an L.
      dp[1][2] = prev[1][1];
    }

    return accumulate(dp.begin(), dp.end(), 0, [](int s, vector<long>& row) {
      return (s + accumulate(row.begin(), row.end(), 0L)) % kMod;
    });
  }
};
