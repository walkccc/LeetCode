class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    int ans = 0;
    // dp[s] := the longest string chain, where s is the last word
    unordered_map<string, int> dp;

    ranges::sort(words, ranges::less{},
                 [](const string& word) { return word.length(); });

    for (const string& word : words) {
      for (int i = 0; i < word.length(); ++i) {
        const string pred = word.substr(0, i) + word.substr(i + 1);
        dp[word] = max(dp[word], (dp.contains(pred) ? dp[pred] : 0) + 1);
      }
      ans = max(ans, dp[word]);
    }

    return ans;
  }
};
