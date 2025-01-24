class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    vector<vector<int>> mem(n, vector<int>(n));
    return lps(s, 0, n - 1, mem);
  }

 private:
  // Returns the length of LPS(s[i..j]).
  int lps(const string& s, int i, int j, vector<vector<int>>& mem) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (mem[i][j] > 0)
      return mem[i][j];
    if (s[i] == s[j])
      return mem[i][j] = 2 + lps(s, i + 1, j - 1, mem);
    return mem[i][j] = max(lps(s, i + 1, j, mem), lps(s, i, j - 1, mem));
  }
};
