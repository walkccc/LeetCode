class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    int ans = 0;
    unordered_map<string, int> dp;

    sort(begin(words), end(words),
         [](const auto& a, const auto& b) { return a.length() < b.length(); });

    for (const string& word : words) {
      for (int i = 0; i < word.length(); ++i) {
        string pred = word.substr(0, i) + word.substr(i + 1);
        dp[word] = max(dp[word], dp[pred] + 1);
      }
      ans = max(ans, dp[word]);
    }

    return ans;
  }
};
