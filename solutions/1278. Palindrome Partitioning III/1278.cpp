class Solution {
 public:
  int palindromePartition(string s, int k) {
    const int n = s.length();
    // dp[i][k] := min cost to make k palindromes by s[0..i)
    dp.resize(n + 1, vector<int>(k + 1, n));
    // cost[i][j] := min cost to make s[i..j] palindrome
    cost.resize(n, vector<int>(n));

    for (int d = 1; d < n; ++d)
      for (int i = 0, j = d; j < n; ++i, ++j)
        cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];

    return palindromePartition(n, k);
  }

 private:
  vector<vector<int>> dp;
  vector<vector<int>> cost;

  int palindromePartition(int n, int k) {
    if (k == 1)
      return cost[0][n - 1];
    int& ans = dp[n][k];
    if (ans < n)
      return ans;

    // try all possible partitions
    for (int i = k - 1; i < n; ++i)
      ans = min(ans, palindromePartition(i, k - 1) + cost[i][n - 1]);

    return ans;
  }
};
