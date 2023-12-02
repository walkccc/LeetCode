class Solution {
 public:
  int numberWays(vector<vector<int>>& hats) {
    constexpr int kMod = 1'000'000'007;
    constexpr int nHats = 40;
    const int nPeople = hats.size();
    const int nAssignments = 1 << nPeople;
    vector<vector<int>> hatToPeople(nHats + 1);
    // dp[i][j] := the number of ways to assign hats 1, 2, ..., i to people,
    // where j is the bitmask of the current assignment
    vector<vector<int>> dp(nHats + 1, vector<int>(nAssignments));
    dp[0][0] = 1;

    for (int i = 0; i < nPeople; ++i)
      for (const int hat : hats[i])
        hatToPeople[hat].push_back(i);

    for (int h = 1; h <= nHats; ++h)
      for (int j = 0; j < nAssignments; ++j) {
        // We can cover the assignment j in 2 ways:
        // 1. Assign the first h - 1 hats to people without using the hat `h`.
        dp[h][j] += dp[h - 1][j];
        dp[h][j] %= kMod;
        for (const int p : hatToPeople[h])
          if (j & 1 << p) {
            // 2. Assign the first h - 1 hats to people without the person `p`
            //    and assign the hat `h` to the person `p`.
            dp[h][j] += dp[h - 1][j ^ 1 << p];
            dp[h][j] %= kMod;
          }
      }

    return dp[nHats][nAssignments - 1];
  }
};
