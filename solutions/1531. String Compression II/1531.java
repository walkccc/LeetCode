class Solution {
  public int getLengthOfOptimalCompression(String s, int k) {
    int[][] mem = new int[s.length()][k + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, kMax));
    return compression(s, 0, k, mem);
  }

  private static final int kMax = 101;

  // Returns the length of the optimal compression of s[i..n) with at most k
  // deletion.
  private int compression(final String s, int i, int k, int[][] mem) {
    if (k < 0)
      return kMax;
    if (i == s.length() || s.length() - i <= k)
      return 0;
    if (mem[i][k] != kMax)
      return mem[i][k];

    int maxFreq = 0;
    int[] count = new int[128];

    // Make letters in s[i..j] be the same.
    // Keep the letter that has the maximum frequency in this range and remove
    // the other letters.
    for (int j = i; j < s.length(); ++j) {
      maxFreq = Math.max(maxFreq, ++count[s.charAt(j)]);
      mem[i][k] = Math.min( //
          mem[i][k],        //
          getLength(maxFreq) + compression(s, j + 1, k - (j - i + 1 - maxFreq), mem));
    }

    return mem[i][k];
  }

  // Returns the length to compress `maxFreq`.
  private int getLength(int maxFreq) {
    if (maxFreq == 1)
      return 1; // c
    if (maxFreq < 10)
      return 2; // [1-9]c
    if (maxFreq < 100)
      return 3; // [1-9][0-9]c
    return 4;   // [1-9][0-9][0-9]c
  }
}
