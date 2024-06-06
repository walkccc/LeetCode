class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    constexpr int kMod = 1'000'000'007;
    const int wordLength = words[0].length();
    // dp[i] := the number of ways to form the first i characters of the
    // `target`
    vector<long> dp(target.size() + 1);
    dp[0] = 1;

    for (int j = 0; j < wordLength; ++j) {
      vector<int> count(26);
      for (const string& word : words)
        ++count[word[j] - 'a'];
      for (int i = target.size(); i > 0; --i) {
        dp[i] += dp[i - 1] * count[target[i - 1] - 'a'];
        dp[i] %= kMod;
      }
    }

    return dp[target.length()];
  };
};
