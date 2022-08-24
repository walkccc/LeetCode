class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int n = s.length();
    const int maxLength = getMaxLength(wordDict);
    const unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    // dp[i] := true if s[0..i) can be segmented
    vector<int> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
      for (int j = i - 1; j >= 0; --j) {
        if (i - j > maxLength)
          break;
        // s[0..j) can be segmented and s[j..i) in wordSet
        // so s[0..i) can be segmented
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }

    return dp[n];
  }

 private:
  int getMaxLength(const vector<string>& wordDict) {
    return max_element(begin(wordDict), end(wordDict),
                       [](const auto& a, const auto& b) {
                         return a.length() < b.length();
                       })
        ->length();
  }
};
