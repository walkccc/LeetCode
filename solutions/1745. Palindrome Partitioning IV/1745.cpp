class Solution {
 public:
  bool checkPartitioning(string s) {
    const int n = s.length();
    // dp[i][j] := true if s[i..j] is palindrome
    dp.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (isPalindrome(s, 0, i) &&
            isPalindrome(s, i + 1, j) &&
            isPalindrome(s, j + 1, n - 1))
          return true;

    return false;
  }

 private:
  vector<vector<int>> dp;

  // return 0 if s[i..j] is not a palindrome
  // return 1 if s[i..j] is a palindrome
  int isPalindrome(const string& s, int i, int j) {
    if (i > j)
      return 1;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == s[j])
      return dp[i][j] = isPalindrome(s, i + 1, j - 1);
    return dp[i][j] = 0;
  }
};
