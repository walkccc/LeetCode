class Solution {
  public int longestPalindromeSubseq(String s) {
    final int n = s.length();
    int[][][] mem = new int[n][n][27];
    return lps(s, 0, n - 1, 26, mem);
  }

  // Returns the length of LPS(s[i..j]), where the previous letter is ('a' + k).
  private int lps(final String s, int i, int j, int k, int[][][] mem) {
    if (i >= j)
      return 0;
    if (mem[i][j][k] > 0)
      return mem[i][j][k];
    if (s.charAt(i) == s.charAt(j) && s.charAt(i) != (char) (k + 'a'))
      return mem[i][j][k] = lps(s, i + 1, j - 1, s.charAt(i) - 'a', mem) + 2;
    return mem[i][j][k] = Math.max(lps(s, i + 1, j, k, mem), lps(s, i, j - 1, k, mem));
  }
}
