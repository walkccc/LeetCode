class Solution {
 public:
  int idealArrays(int n, int maxValue) {
    constexpr int kMod = 1'000'000'007;
    // Since 2^14 > 10^4, the longest strictly increasing array is [1, 2, 4,
    // ..., 2^13]
    const int maxLength = min(14, n);
    const vector<vector<int>> factors = getFactors(maxValue);
    // dp[i][j] := the number of strictly increasing ideal arrays of length i
    // ending in j
    // dp[i][j] := sum(dp[i - 1][k]), where j % k == 0
    // dp[i][0] := sum(dp[i][j]) where 1 <= j <= maxValue
    vector<vector<unsigned long long>> dp(
        maxLength + 1, vector<unsigned long long>(maxValue + 1));
    memo.resize(n, vector<unsigned long long>(maxLength, -1));
    unsigned long long ans = 0;

    for (int j = 1; j <= maxValue; ++j)
      dp[1][j] = 1;

    for (int i = 2; i <= maxLength; ++i)
      for (int j = 1; j <= maxValue; ++j)
        for (const int k : factors[j]) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= kMod;
        }

    for (int i = 1; i <= maxLength; ++i)
      for (int j = 1; j <= maxValue; ++j) {
        dp[i][0] += dp[i][j];
        dp[i][0] %= kMod;
      }

    for (int i = 1; i <= maxLength; ++i) {
      // nCk(n - 1, i - 1) := the number of ways to create an ideal array of
      // length n from a strictly increasing array of length i
      ans += dp[i][0] * nCk(n - 1, i - 1);
      ans %= kMod;
    }

    return ans;
  }

 private:
  vector<vector<unsigned long long>> memo;

  vector<vector<int>> getFactors(int maxValue) {
    vector<vector<int>> factors(maxValue + 1);
    for (int i = 1; i <= maxValue; ++i)
      // Start from i * 2 because of strictly increasing.
      for (int j = i * 2; j <= maxValue; j += i)
        factors[j].push_back(i);
    return factors;
  }

  unsigned long long nCk(int n, int k, int kMod = 1e9 + 7) {
    if (k == 0)
      return 1;
    if (n == k)
      return 1;
    if (memo[n][k] != -1)
      return memo[n][k];
    return memo[n][k] = (nCk(n - 1, k) + nCk(n - 1, k - 1)) % kMod;
  }
};
