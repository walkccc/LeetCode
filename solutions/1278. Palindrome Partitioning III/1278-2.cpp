class Solution {
 public:
  int palindromePartition(string s, int K) {
    const int n = s.length();
    // dp[i][k] := the minimum cost to make k palindromes by s[0..i)
    vector<vector<int>> dp(n + 1, vector<int>(K + 1, n));
    // cost[i][j] := the minimum cost to make s[i..j] palindrome
    vector<vector<int>> cost(n, vector<int>(n));

    for (int d = 1; d < n; ++d)
      for (int i = 0, j = d; j < n; ++i, ++j)
        cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];

    for (int i = 1; i <= n; ++i)
      dp[i][1] = cost[0][i - 1];

    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[j][i - 1]);

    return dp[n][K];
  }
};
