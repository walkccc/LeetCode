class Solution {
 public:
  int minimumCost(string target, vector<string>& words, vector<int>& costs) {
    const int n = target.length();
    // dp[i] := the minimum cost to construct target[0..i)
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < words.size(); ++j)
        if (i >= words[j].length() &&
            target.substr(i - words[j].length(), words[j].length()) ==
                words[j] &&
            dp[i - words[j].length()] != INT_MAX)
          dp[i] = min(dp[i], dp[i - words[j].length()] + costs[j]);

    return dp[n] == INT_MAX ? -1 : dp[n];
  }
};
