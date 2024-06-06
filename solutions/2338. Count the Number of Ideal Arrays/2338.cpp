class Solution {
 public:
  int idealArrays(int n, int maxValue) {
    // Since 2^14 > 10^4, the longest strictly increasing array is [1, 2, 4,
    // ..., 2^13]
    const int maxLength = min(14, n);
    const vector<vector<int>> factors = getFactors(maxValue);
    // dp[i][j] := the number of strictly increasing ideal arrays of length i
    // ending in j
    // dp[i][j] := sum(dp[i - 1][k]), where j % k == 0
    // dp[i][0] := sum(dp[i][j]) where 1 <= j <= maxValue
    vector<vector<long>> dp(maxLength + 1, vector<long>(maxValue + 1));
    vector<vector<long>> mem(n, vector<long>(maxLength, -1));
    long ans = 0;

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
      ans += dp[i][0] * nCk(n - 1, i - 1, mem);
      ans %= kMod;
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  vector<vector<int>> getFactors(int maxValue) {
    vector<vector<int>> factors(maxValue + 1);
    for (int i = 1; i <= maxValue; ++i)
      // Start from i * 2 because of strictly increasing.
      for (int j = i * 2; j <= maxValue; j += i)
        factors[j].push_back(i);
    return factors;
  }

  long nCk(int n, int k, vector<vector<long>>& mem) {
    if (k == 0)
      return 1;
    if (n == k)
      return 1;
    if (mem[n][k] != -1)
      return mem[n][k];
    return mem[n][k] = (nCk(n - 1, k, mem) + nCk(n - 1, k - 1, mem)) % kMod;
  }
};
