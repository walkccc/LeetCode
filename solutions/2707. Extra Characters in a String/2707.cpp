class Solution {
 public:
  // Similar to 139. Word Break
  int minExtraChar(string s, vector<string>& dictionary) {
    const int n = s.length();
    const unordered_set<string> dictionarySet{dictionary.begin(),
                                              dictionary.end()};
    // dp[i] := the minimum extra letters if breaking up s[0..i) optimally
    vector<int> dp(n + 1, n);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        // s[j..i) is in the `dictionarySet`.
        if (dictionarySet.count(s.substr(j, i - j)))
          dp[i] = min(dp[i], dp[j]);
        // s[j..i) are extra letters.
        else
          dp[i] = min(dp[i], dp[j] + i - j);

    return dp[n];
  }
};
