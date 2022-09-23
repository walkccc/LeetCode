class Solution {
 public:
  int numberWays(vector<vector<int>>& hats) {
    constexpr int kMod = 1'000'000'007;
    constexpr int nHats = 40;
    const int nPeople = hats.size();
    const int nAssignments = 1 << nPeople;
    vector<vector<int>> hatToPeople(nHats + 1);
    // dp[i][j] := # of ways to assign hats 1, 2, ..., i to people in mask j
    vector<vector<int>> dp(nHats + 1, vector<int>(nAssignments));
    dp[0][0] = 1;

    for (int i = 0; i < nPeople; ++i)
      for (const int hat : hats[i])
        hatToPeople[hat].push_back(i);

    for (int h = 1; h <= nHats; ++h)
      // for each assignment j of people
      for (int j = 0; j < nAssignments; ++j) {
        // we can cover the assignment j in 2 ways
        // (1) by first h - 1 hats (i.e., w/o hat h)
        dp[h][j] += dp[h - 1][j];
        dp[h][j] %= kMod;
        for (const int p : hatToPeople[h])
          if (j & 1 << p) {
            // (2) by first h - 1 hats assigned to people w/o person p and
            //     hat h assigned to person p
            dp[h][j] += dp[h - 1][j ^ 1 << p];
            dp[h][j] %= kMod;
          }
      }

    return dp[nHats][nAssignments - 1];
  }
};
