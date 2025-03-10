class Solution {
 public:
  int numberWays(vector<vector<int>>& hats) {
    constexpr int kMod = 1'000'000'007;
    constexpr int nHats = 40;
    const int nPeople = hats.size();
    const int nAssignments = 1 << nPeople;
    vector<vector<int>> hatToPeople(nHats + 1);
    // dp[i] := the number of ways to assign the hats so far to people, where i
    // is the bitmask of the current assignment
    vector<int> dp(nAssignments);
    dp[0] = 1;

    for (int i = 0; i < nPeople; ++i)
      for (const int hat : hats[i])
        hatToPeople[hat].push_back(i);

    for (int h = 1; h <= nHats; ++h)
      for (int j = nAssignments - 1; j >= 0; --j)
        for (const int p : hatToPeople[h])
          if (j >> p & 1) {
            dp[j] += dp[j ^ 1 << p];
            dp[j] %= kMod;
          }

    return dp[nAssignments - 1];
  }
};
