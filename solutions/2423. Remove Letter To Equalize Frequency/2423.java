class Solution {
  public boolean equalFrequency(String word) {
    int[] count = new int[26];

    for (final char c : word.toCharArray())
      ++count[c - 'a'];

    // Try to remove each letter, then check if the frequency of all the letters
    // in the `word` are equal.
    for (final char c : word.toCharArray()) {
      --count[c - 'a'];
      if (equalFreq(count))
        return true;
      ++count[c - 'a'];
    }

    return false;
  }

  private boolean equalFreq(int[] count) {
    int theFreq = -1;
    for (final int freq : count) {
      if (freq == 0 || freq == theFreq)
        continue;
      if (theFreq == -1)
        theFreq = freq;
      else
        return false;
    }
    return true;
  }
}
