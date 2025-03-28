class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int n = s.length();
    const int maxLength = getMaxLength(wordDict);
    const unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
    // dp[i] := true if s[0..i) can be segmented
    vector<int> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
      for (int j = i - 1; j >= 0; --j) {
        if (i - j > maxLength)
          break;
        // s[0..j) can be segmented and s[j..i) is in the wordSet, so s[0..i)
        // can be segmented.
        if (dp[j] && wordSet.contains(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }

    return dp[n];
  }

 private:
  int getMaxLength(const vector<string>& wordDict) {
    return ranges::max_element(wordDict, ranges::less{},
                               [](const string& word) {
      return word.length();
    })->length();
  }
};
