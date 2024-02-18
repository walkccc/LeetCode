class Solution {
 public:
  string findTheString(vector<vector<int>>& lcp) {
    const int n = lcp.size();
    constexpr char nonLetter = 'a' - 1;
    char c = nonLetter;
    vector<char> word(n, nonLetter);

    for (int i = 0; i < n; ++i) {
      if (word[i] != nonLetter)  // There's a candidate already.
        continue;
      if (++c > 'z')  // Run out of letters, so return "".
        return "";
      // No need to consider [0..i - 1] since they were considered.
      for (int j = i; j < n; ++j)
        if (lcp[i][j] > 0)
          word[j] = c;
    }

    // Check if `word` is valid.
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        const int nextLcp = i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] : 0;
        const int currLcp = word[i] == word[j] ? 1 + nextLcp : 0;
        if (lcp[i][j] != currLcp)
          return "";
      }

    string ans;
    for (const char c : word)
      ans += c;
    return ans;
  }
};
