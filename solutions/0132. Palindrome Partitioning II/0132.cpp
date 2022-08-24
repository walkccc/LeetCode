class Solution {
 public:
  int minCut(string s) {
    const int n = s.length();
    // isPalindrome[i][j] := true if s[i..j] is a palindrome
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
    // dp[i] := min cuts needed for a palindrome partitioning of s[0..i]
    vector<int> dp(n, n);

    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = l - 1; j < n; ++i, ++j)
        isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i + 1][j - 1];

    for (int i = 0; i < n; ++i) {
      if (isPalindrome[0][i]) {
        dp[i] = 0;
        continue;
      }

      // try all possible partitions
      for (int j = 0; j < i; ++j)
        if (isPalindrome[j + 1][i])
          dp[i] = min(dp[i], dp[j] + 1);
    }

    return dp.back();
  }
};
