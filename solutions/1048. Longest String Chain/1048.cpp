class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    const unordered_set<string> wordsSet{words.begin(), words.end()};
    int ans = 0;

    for (const string& word : words)
      ans = max(ans, longestStrChain(word, wordsSet));

    return ans;
  }

 private:
  // dp[s] := the longest string chain, where s is the last word
  unordered_map<string, int> dp;

  int longestStrChain(const string& s, const unordered_set<string>& wordsSet) {
    if (const auto it = dp.find(s); it != dp.cend())
      return it->second;

    int ans = 1;

    for (int i = 0; i < s.length(); ++i) {
      const string pred = s.substr(0, i) + s.substr(i + 1);
      if (wordsSet.count(pred))
        ans = max(ans, longestStrChain(pred, wordsSet) + 1);
    }

    return dp[s] = ans;
  }
};
