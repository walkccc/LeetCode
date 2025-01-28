class Solution {
  public boolean equalFrequency(String word) {
    int[] count = new int[26];

    for (final char c : word.toCharArray())
      ++count[c - 'a'];

    // Try to remove each letter, then check if the frequency of all the letters
    // in `word` are equal.
    for (final char c : word.toCharArray()) {
      --count[c - 'a'];
      if (equalFreq(count))
        return true;
      ++count[c - 'a'];
    }

    return false;
  }

  private static final int kMax = 101;

  private boolean equalFreq(int[] count) {
    int minfreq = kMax;
    int maxfreq = 0;
    for (final int freq : count)
      if (freq > 0) {
        minfreq = Math.min(minfreq, freq);
        maxfreq = Math.max(maxfreq, freq);
      }
    return minfreq == maxfreq;
  }
}
