class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    int ans = 0;
    // dp[s] := longest string chain where s is the last word
    unordered_map<string, int> dp;

    sort(begin(words), end(words),
         [](const auto& a, const auto& b) { return a.length() < b.length(); });

    for (const auto& word : words) {
      for (int i = 0; i < word.length(); ++i) {
        const string pred = word.substr(0, i) + word.substr(i + 1);
        dp[word] = max(dp[word], (dp.count(pred) ? dp[pred] : 0) + 1);
      }
      ans = max(ans, dp[word]);
    }

    return ans;
  }
};
