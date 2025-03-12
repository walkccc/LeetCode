class Solution {
 public:
  int numberOfPermutations(int n, vector<vector<int>>& requirements) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMaxInversions = 400;
    // dp[i][j] := the number of ways to arrange the first i numbers of the
    // permutation s.t. there are j inversions
    vector<vector<int>> dp(n + 1, vector<int>(kMaxInversions + 1));
    vector<int> endToCnt(n + 1, -1);

    for (const vector<int>& requirement : requirements) {
      const int end = requirement[0];
      const int cnt = requirement[1];
      endToCnt[end + 1] = cnt;
    }

    // There's only one way to arrange a single number with zero inversions.
    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i)
      for (int newInversions = 0; newInversions < i; ++newInversions)
        for (int j = 0; j + newInversions <= kMaxInversions; ++j) {
          const int inversionsAfterInsertion = j + newInversions;
          if (endToCnt[i] != -1 && inversionsAfterInsertion != endToCnt[i])
            continue;
          dp[i][inversionsAfterInsertion] += dp[i - 1][j];
          dp[i][inversionsAfterInsertion] %= kMod;
        }

    return dp[n][endToCnt[n]];
  }
};
