class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    constexpr int kMod = 1'000'000'007;
    const int wordLength = words[0].length();
    // dp[i][j] := the number of ways to form the first i characters of the
    // `target` using the j first characters in each word
    vector<vector<int>> dp(target.length() + 1, vector<int>(wordLength + 1));
    // counts[j] := the count map of words[i][j], where 0 <= i < |words|
    vector<vector<int>> counts(wordLength, vector<int>(26));

    for (int i = 0; i < wordLength; ++i)
      for (const string& word : words)
        ++counts[i][word[i] - 'a'];

    dp[0][0] = 1;

    for (int i = 0; i <= target.length(); ++i)
      for (int j = 0; j < wordLength; ++j) {
        if (i < target.length())
          // Pick the character target[i] from word[j].
          dp[i + 1][j + 1] =
              dp[i][j] * static_cast<long>(counts[j][target[i] - 'a']) % kMod;
        // Skip the word[j].
        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % kMod;
      }

    return dp[target.length()][wordLength];
  };
};
