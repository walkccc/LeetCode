class Solution {
 public:
  int palindromePartition(string s, int k) {
    const int n = s.length();

    vector<vector<int>> memo(n + 1, vector<int>(k + 1, n));
    vector<vector<int>> cost(n, vector<int>(n));

    // cost[i][j] := min cost to make s[i..j] palindrome
    for (int length = 2; length <= n; ++length)
      for (int i = 0, j = length - 1; j < n; ++i, ++j)
        cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];

    // dp(n, k) := min cost to make k palindromes by s[0..n)
    function<int(int, int)> dp = [&](int n, int k) {
      if (k == 1) return cost[0][n - 1];
      int& ans = memo[n][k];
      if (ans < n) return ans;

      // try all possible partitions
      for (int i = k - 1; i < n; ++i)
        ans = min(ans, dp(i, k - 1) + cost[i][n - 1]);

      return ans;
    };

    return dp(n, k);
  }
};