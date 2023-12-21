class Solution {
 public:
  string encode(string s) {
    const int n = s.length();
    // dp[i][j] := the shortest encoded string of s[i..j]
    dp.resize(n, vector<string>(n));
    return encode(s, 0, n - 1);
  }

 private:
  vector<vector<string>> dp;

  string encode(const string& s, int i, int j) {
    if (!dp[i][j].empty())
      return dp[i][j];

    const string& curr = s.substr(i, j - i + 1);
    dp[i][j] = curr;

    if (dp[i][j].length() < 5)
      return dp[i][j];

    // Try all the possible partitions.
    for (int k = i; k < j; ++k) {
      const string& l = encode(s, i, k);
      const string& r = encode(s, k + 1, j);
      if (l.length() + r.length() < dp[i][j].length())
        dp[i][j] = l + r;
    }

    // Try to compress the string.
    // e.g. s = aabaabaab -> 3[aab]
    for (int k = i; k <= j; ++k) {
      const string& pattern = s.substr(i, k - i + 1);
      if (curr.length() % pattern.length() == 0 &&
          regex_replace(curr, regex(pattern), "").empty()) {
        const string& candidate = to_string(curr.length() / pattern.length()) +
                                  '[' + encode(s, i, k) + ']';
        if (candidate.length() < dp[i][j].length())
          dp[i][j] = candidate;
      }
    }

    return dp[i][j];
  }
};
