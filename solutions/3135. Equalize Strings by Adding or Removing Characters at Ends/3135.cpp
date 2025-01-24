class Solution {
 public:
  int minOperations(string initial, string target) {
    const int m = initial.length();
    const int n = target.length();
    // dp[i][j] := the length of LCS(initial[0..i), target[0..j))
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (initial[i - 1] == target[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];

    const int maxCommonLength = accumulate(
        dp.begin(), dp.end(), 0, [](int subtotal, const vector<int>& row) {
      return max(subtotal, ranges::max(row));
    });
    return m + n - 2 * maxCommonLength;
  }
};
