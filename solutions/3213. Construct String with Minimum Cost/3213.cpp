class Solution {
 public:
  int minimumCost(string target, vector<string>& words, vector<int>& costs) {
    constexpr int kMax = 1'000'000'000;
    const int n = target.length();
    // dp[i] := the minimum cost to construct target[0..i)
    vector<int> dp(n + 1, kMax);
    dp[0] = 0;
    // minCost[c][word] := the minimum cost to construct word starting with `c`
    vector<unordered_map<string, int>> minCost(26);

    for (int i = 0; i < words.size(); ++i) {
      const int index = words[i][0] - 'a';
      const string& word = words[i];
      minCost[index][word] =
          min(minCost[index].contains(word) ? minCost[index][word] : kMax,
              costs[i]);
    }

    for (int i = 0; i < n; ++i)
      for (const auto& [word, cost] : minCost[target[i] - 'a']) {
        const int j = i + word.length();
        if (j <= n && cost + dp[i] < dp[j] &&
            string_view(target.data() + i, word.length()) == word)
          dp[j] = cost + dp[i];
      }

    return dp[n] == kMax ? -1 : dp[n];
  }
};
