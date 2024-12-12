class Solution {
 public:
  int maxPalindromes(string s, int k) {
    const int n = s.length();
    // dp[i] := the maximum number of substrings in the first i chars of s
    vector<int> dp(n + 1);

    // If a palindrome is a substring of another palindrome, then considering
    // the longer palindrome won't increase the number of non-overlapping
    // palindromes. So, we only need to consider the shorter one. Also,
    // considering palindromes with both k length and k + 1 length ensures that
    // we look for both even and odd length palindromes.
    for (int i = k; i <= n; ++i) {
      dp[i] = dp[i - 1];
      // Consider palindrome with length k.
      if (isPalindrome(s, i - k, i - 1))
        dp[i] = max(dp[i], 1 + dp[i - k]);
      // Consider palindrome with length k + 1.
      if (isPalindrome(s, i - k - 1, i - 1))
        dp[i] = max(dp[i], 1 + dp[i - k - 1]);
    }

    return dp[n];
  }

 private:
  // Returns true is s[i..j) is a palindrome.
  bool isPalindrome(const string& s, int l, int r) {
    if (l < 0)
      return false;
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};
