class Solution {
 public:
  // Similar to 516. Longest Palindromic Subsequence
  int longestPalindromicSubsequence(string s, int k) {
    const int n = s.length();
    vector<vector<vector<int>>> mem(
        n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    return lps(s, 0, n - 1, k, mem);
  }

 private:
  // Returns the length of LPS(s[i..j]) with at most `op` operations.
  int lps(const string& s, int i, int j, int op,
          vector<vector<vector<int>>>& mem) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (mem[i][j][op] != -1)
      return mem[i][j][op];
    if (s[i] == s[j])
      return mem[i][j][op] = 2 + lps(s, i + 1, j - 1, op, mem);
    mem[i][j][op] = max(lps(s, i + 1, j, op, mem), lps(s, i, j - 1, op, mem));
    const int cost = getCost(s[i], s[j]);
    if (cost <= op)
      mem[i][j][op] =
          max(mem[i][j][op], 2 + lps(s, i + 1, j - 1, op - cost, mem));
    return mem[i][j][op];
  }

  int getCost(char a, char b) {
    const int dist = abs(a - b);
    return min(dist, 26 - dist);
  }
};
