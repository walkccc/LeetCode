class Solution {
 public:
  int numberWays(vector<vector<int>>& hats) {
    constexpr int nHats = 40;
    const int nPeople = hats.size();
    hatToPeople.resize(nHats + 1);
    // dp[i][j] := the number of ways to assign hats 1, 2, ..., i to people,
    // where j is the bitmask of the current assignment
    dp.resize(nHats + 1, vector<int>(1 << nPeople, -1));

    for (int i = 0; i < nPeople; ++i)
      for (const int hat : hats[i])
        hatToPeople[hat].push_back(i);

    return ways(hats, 0, 1);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<int>> hatToPeople;
  vector<vector<int>> dp;

  int ways(const vector<vector<int>>& hats, int assignment, int h) {
    // All the people are assigned.
    if (assignment == (1 << hats.size()) - 1)
      return 1;
    if (h > 40)
      return 0;
    if (dp[h][assignment] != -1)
      return dp[h][assignment];

    // Don't wear the hat `h`.
    int ans = ways(hats, assignment, h + 1);

    for (const int p : hatToPeople[h]) {
      // The person `p` was assigned the hat `h` before.
      if (assignment & 1 << p)
        continue;
      // Assign the hat `h` to the person `p`.
      ans += ways(hats, assignment | 1 << p, h + 1);
      ans %= kMod;
    }

    return dp[h][assignment] = ans;
  }
};
