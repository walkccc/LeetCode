class Solution {
 public:
  // 3503. Longest Palindrome After Substring Concatenation I
  int longestPalindrome(string s, string t) {
    const int m = s.length();
    const int n = t.length();
    vector<int> suffix = getPalindromeLengths(s, true);
    vector<int> prefix = getPalindromeLengths(t, false);
    int ans = max(ranges::max(suffix), ranges::max(prefix));
    // dp[i][j] := the longest length of palindrome starting in s[i] and ending
    // in t[j]
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
      for (int j = n - 1; j >= 0; --j)
        if (s[i] == t[j]) {
          dp[i][j] = 2 + (i > 0 && j < n - 1 ? dp[i - 1][j + 1] : 0);
          const int extend =
              max(i + 1 < m ? suffix[i + 1] : 0, j > 0 ? prefix[j - 1] : 0);
          ans = max(ans, dp[i][j] + extend);
        }

    return ans;
  }

 private:
  vector<int> getPalindromeLengths(const string& s, bool isSuffix) {
    const int n = s.length();
    // dp[i][j] := True if s[i..j] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n));
    // lengths[i] := length of longest palindrome in s[i..n - 1]
    vector<int> lengths(n);
    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          const int index = isSuffix ? i : j;
          lengths[index] = max(lengths[index], j - i + 1);
        }
    return lengths;
  }
};
