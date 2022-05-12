class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    const unordered_set<string> wordsSet{begin(words), end(words)};
    int ans = 0;

    for (const auto& word : words)
      ans = max(ans, longestStrChain(word, wordsSet));

    return ans;
  }

 private:
  // dp[s] := longest string chain where s is the last word
  unordered_map<string, int> dp;

  int longestStrChain(const string& s, const unordered_set<string>& wordsSet) {
    if (dp.count(s))
      return dp[s];

    int ans = 1;

    for (int i = 0; i < s.length(); ++i) {
      const string pred = s.substr(0, i) + s.substr(i + 1);
      if (wordsSet.count(pred))
        ans = max(ans, longestStrChain(pred, wordsSet) + 1);
    }

    return dp[s] = ans;
  }
};
