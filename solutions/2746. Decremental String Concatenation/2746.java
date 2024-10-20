class Solution {
  public int minimizeConcatenatedLength(String[] words) {
    int[][][] mem = new int[words.length][26][26];
    return words[0].length() + minimizeConcatenatedLength(words, 1, words[0].charAt(0),
                                                          words[0].charAt(words[0].length() - 1),
                                                          mem);
  }

  private int minimizeConcatenatedLength(String[] words, int i, char first, char last,
                                         int[][][] mem) {
    if (i == words.length)
      return 0;
    final int j = first - 'a';
    final int k = last - 'a';
    if (mem[i][j][k] > 0)
      return mem[i][j][k];
    final char nextFirst = words[i].charAt(0);
    final char nextLast = words[i].charAt(words[i].length() - 1);
    return mem[i][j][k] =   //
        words[i].length() + //
        Math.min(
            // join(words[i - 1], words[i])
            minimizeConcatenatedLength(words, i + 1, first, nextLast, mem) -
                (last == nextFirst ? 1 : 0),
            // join(words[i], words[i - 1])
            minimizeConcatenatedLength(words, i + 1, nextFirst, last, mem) -
                (first == nextLast ? 1 : 0));
  }
}
