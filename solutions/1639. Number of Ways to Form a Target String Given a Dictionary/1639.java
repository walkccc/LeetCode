class Solution {
  public int numWays(String[] words, String target) {
    final int wordLength = words[0].length();
    Integer[][] mem = new Integer[target.length()][wordLength];
    // counts[j] := the count map of words[i][j], where 0 <= i < |words|
    int[][] counts = new int[wordLength][26];

    for (int i = 0; i < wordLength; ++i)
      for (final String word : words)
        ++counts[i][word.charAt(i) - 'a'];

    return numWays(target, 0, 0, counts, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of ways to form target[i..n) using word[j..n).
  private int numWays(final String target, int i, int j, int[][] counts, Integer[][] mem) {
    if (i == target.length())
      return 1;
    if (j == counts.length)
      return 0;
    if (mem[i][j] != null)
      return mem[i][j];
    return mem[i][j] = (int) ((numWays(target, i + 1, j + 1, counts, mem) *
                                   (long) (counts[j][target.charAt(i) - 'a']) +
                               numWays(target, i, j + 1, counts, mem)) %
                              kMod);
  }
}
