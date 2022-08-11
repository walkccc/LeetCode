class Solution {
 public:
  string encode(string s) {
    const int n = s.length();
    // dp[i][j] := shortest encoded string of s[i..j]
    vector<vector<string>> dp(n, vector<string>(n));

    for (int d = 0; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        const string& curr = s.substr(i, j - i + 1);
        dp[i][j] = curr;

        if (dp[i][j].length() < 5)
          continue;

        // try all possible partitions
        for (int k = i; k < j; ++k)
          if (dp[i][k].length() + dp[k + 1][j].length() < dp[i][j].length())
            dp[i][j] = dp[i][k] + dp[k + 1][j];

        // try to compress theString
        // e.g. s = aabaabaab -> 3[aab]
        for (int k = i; k <= j; ++k) {
          const string& pattern = s.substr(i, k - i + 1);
          if (curr.length() % pattern.length() == 0 &&
              regex_replace(curr, regex(pattern), "").empty()) {
            const string& candidate =
                to_string(curr.length() / pattern.length()) + '[' + dp[i][k] +
                ']';
            if (candidate.length() < dp[i][j].length())
              dp[i][j] = candidate;
          }
        }
      }
    }

    return dp[0][n - 1];
  }
};
