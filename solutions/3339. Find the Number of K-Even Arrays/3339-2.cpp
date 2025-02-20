class Solution {
 public:
  int countOfArrays(int n, int m, int k) {
    constexpr int kMod = 1'000'000'007;
    const int even = m / 2;    // the number of even numbers in [1, m]
    const int odd = m - even;  // the number of odd numbers in [1, m]
    // dp[j][0/1] := the number of arrays of length so far i with j consecutive
    // even number pairs ending in an even number (0) or an odd number (1)
    vector<vector<int>> dp(k + 1, vector<int>(2));

    // Base case: arrays of length 1
    // For an array of length 1, we can't have any even number pairs yet.
    dp[0][0] = even;
    dp[0][1] = odd;

    for (int i = 2; i <= n; ++i) {
      vector<vector<int>> newDp(k + 1, vector<int>(2));
      for (int j = 0; j <= k; ++j) {
        // 1. Appending an even number to an array ending in an even number
        //    creates a new consecutive even number pair.
        // 2. Appending an even number to an array ending in an odd number.
        newDp[j][0] = (static_cast<long>(j > 0 ? dp[j - 1][0] : 0) * even +
                       static_cast<long>(dp[j][1]) * even) %
                      kMod;
        // 3. Appending an odd number to an array.
        newDp[j][1] = static_cast<long>(dp[j][0] + dp[j][1]) * odd % kMod;
      }
      dp = std::move(newDp);
    }

    return (dp[k][0] + dp[k][1]) % kMod;
  }
};
