class Solution {
  // Similar to 516. Longest Palindromic Subsequence
  public int longestPalindromicSubsequence(String s, int k) {
    final int n = s.length();
    Integer[][][] mem = new Integer[n][n][k + 1];
    return lps(s, 0, n - 1, k, mem);
  }

  // Returns the length of LPS(s[i..j]) with at most `op` operations.
  private int lps(String s, int i, int j, int op, Integer[][][] mem) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (mem[i][j][op] != null)
      return mem[i][j][op];
    if (s.charAt(i) == s.charAt(j))
      return mem[i][j][op] = 2 + lps(s, i + 1, j - 1, op, mem);
    mem[i][j][op] = Math.max(lps(s, i + 1, j, op, mem), lps(s, i, j - 1, op, mem));
    final int cost = getCost(s.charAt(i), s.charAt(j));
    if (cost <= op)
      mem[i][j][op] = Math.max(mem[i][j][op], 2 + lps(s, i + 1, j - 1, op - cost, mem));
    return mem[i][j][op];
  }

  private int getCost(char a, char b) {
    final int dist = Math.abs(a - b);
    return Math.min(dist, 26 - dist);
  }
}
