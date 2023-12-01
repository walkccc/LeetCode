class Solution {
 public:
  int minimizeConcatenatedLength(vector<string>& words) {
    // dp[i][first][last] := the minimum concatenated length of the first i
    // words starting with the `first` and ending in the `last`
    dp.resize(words.size(), vector<vector<int>>(26, vector<int>(26)));
    return words[0].length() + minimizeConcatenatedLength(
                                   words, 1, words[0].front(), words[0].back());
  }

 private:
  vector<vector<vector<int>>> dp;

  int minimizeConcatenatedLength(const vector<string>& words, int i, char first,
                                 char last) {
    if (i == words.size())
      return 0;
    if (dp[i][first - 'a'][last - 'a'] > 0)
      return dp[i][first - 'a'][last - 'a'];
    const char nextFirst = words[i].front();
    const char nextLast = words[i].back();
    return dp[i][first - 'a'][last - 'a'] =
               words[i].length() +
               min(
                   // join(words[i - 1], words[i])
                   minimizeConcatenatedLength(words, i + 1, first, nextLast) -
                       (last == nextFirst ? 1 : 0),
                   // join(words[i], words[i - 1])
                   minimizeConcatenatedLength(words, i + 1, nextFirst, last) -
                       (first == nextLast ? 1 : 0));
  }
};
