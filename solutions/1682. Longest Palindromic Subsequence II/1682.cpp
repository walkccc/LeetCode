class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    vector<vector<vector<int>>> mem(n, vector<vector<int>>(n, vector<int>(27)));
    return lps(s, 0, n - 1, 26, mem);
  }

 private:
  // Returns the length of LPS(s[i..j]), where the previous letter is ('a' + k).
  int lps(const string& s, int i, int j, int k,
          vector<vector<vector<int>>>& mem) {
    if (i >= j)
      return 0;
    if (mem[i][j][k] > 0)
      return mem[i][j][k];
    if (s[i] == s[j] && s[i] != 'a' + k)
      return mem[i][j][k] = lps(s, i + 1, j - 1, s[i] - 'a', mem) + 2;
    return mem[i][j][k] =
               max(lps(s, i + 1, j, k, mem), lps(s, i, j - 1, k, mem));
  }
};
