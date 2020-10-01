class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();

    vector<vector<int>> memo(n, vector<int>(n));

    // dp(i, j) := LPS's length in s[i..j]
    function<int(int, int)> dp = [&](int i, int j) {
      if (i > j) return 0;
      if (i == j) return 1;
      int& ans = memo[i][j];
      if (ans) return ans;
      if (s[i] == s[j]) return ans = 2 + dp(i + 1, j - 1);

      return ans = max(dp(i + 1, j), dp(i, j - 1));
    };

    return dp(0, n - 1);
  }
};