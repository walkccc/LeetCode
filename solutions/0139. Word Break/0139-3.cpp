class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int n = s.length();
    unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    // dp[i] := true if s[0..i) can be segmented
    vector<bool> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        // s[0..j) can be segmented and s[j..i) in wordSet
        // so s[0..i) can be segmented
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }

    return dp[n];
  }
};
