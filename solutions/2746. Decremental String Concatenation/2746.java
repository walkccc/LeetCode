class Solution {
  public int minimizeConcatenatedLength(String[] words) {
    // dp[i][first][last] := the minimum concatenated length of the first i
    // words starting with the `first` and ending in the `last`
    dp = new int[words.length][26][26];
    return words[0].length() + minimizeConcatenatedLength(words, 1, words[0].charAt(0),
                                                          words[0].charAt(words[0].length() - 1));
  }

  private int[][][] dp;

  private int minimizeConcatenatedLength(String[] words, int i, char first, char last) {
    if (i == words.length)
      return 0;
    if (dp[i][first - 'a'][last - 'a'] > 0)
      return dp[i][first - 'a'][last - 'a'];
    final char nextFirst = words[i].charAt(0);
    final char nextLast = words[i].charAt(words[i].length() - 1);
    return dp[i][first - 'a'][last - 'a'] =
               words[i].length() +
               Math.min(minimizeConcatenatedLength(words, i + 1, first, nextLast) -
                            (last == nextFirst ? 1 : 0),
                        minimizeConcatenatedLength(words, i + 1, nextFirst, last) -
                            (first == nextLast ? 1 : 0));
  }
}
