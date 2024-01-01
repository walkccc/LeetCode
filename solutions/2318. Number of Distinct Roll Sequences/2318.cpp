class Solution {
 public:
  int distinctSequences(int n) {
    // dp[n][prev][prevPrev] := the number of distinct sequences for n dices
    // with `prev` and `prevPrev`
    dp.resize(n + 1, vector<vector<int>>(7, vector<int>(7)));
    return distinctSequences(n, 0, 0);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<vector<int>>> dp;

  int distinctSequences(int n, int prev, int prevPrev) {
    if (n == 0)
      return 1;
    if (dp[n][prev][prevPrev])
      return dp[n][prev][prevPrev];

    for (int dice = 1; dice <= 6; ++dice)
      if (dice != prev && dice != prevPrev &&
          (prev == 0 || gcd(dice, prev) == 1)) {
        dp[n][prev][prevPrev] += distinctSequences(n - 1, dice, prev);
        dp[n][prev][prevPrev] %= kMod;
      }

    return dp[n][prev][prevPrev];
  }
};
