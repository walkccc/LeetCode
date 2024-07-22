/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 *   public InfiniteStream(int[] bits);
 *   public int next();
 * }
 */

class Solution {
  public int findPattern(InfiniteStream stream, int[] pattern) {
    int[] lps = getLPS(pattern);
    int i = 0;   // stream's index
    int j = 0;   // pattern's index
    int bit = 0; // the bit in the stream
    boolean readNext = false;
    while (true) {
      if (!readNext) {
        bit = stream.next();
        readNext = true;
      }
      if (bit == pattern[j]) {
        ++i;
        readNext = false;
        ++j;
        if (j == pattern.length)
          return i - j;
      }
      // Mismatch after j matches.
      else if (j > 0) {
        // Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1];
      } else {
        ++i;
        readNext = false;
      }
    }
  }

  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // pattern[0..i] which is also a suffix of this substring.
  private int[] getLPS(int[] pattern) {
    int[] lps = new int[pattern.length];
    int j = 0;
    for (int i = 1; i < pattern.length; ++i) {
      while (j > 0 && pattern[j] != pattern[i])
        j = lps[j - 1];
      if (pattern[i] == pattern[j])
        lps[i] = ++j;
    }
    return lps;
  }
}
