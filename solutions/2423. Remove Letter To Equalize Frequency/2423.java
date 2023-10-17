class Solution {
  public boolean equalFrequency(String word) {
    int[] count = new int[26];

    for (final char c : word.toCharArray())
      ++count[c - 'a'];

    // Try to remove each letter, then check if the frequency of all letters in
    // word are equal
    for (final char c : word.toCharArray()) {
      --count[c - 'a'];
      if (equalCount(count))
        return true;
      ++count[c - 'a'];
    }

    return false;
  }

  private boolean equalCount(int[] count) {
    int freq = -1;
    for (final int c : count) {
      if (c == 0 || c == freq)
        continue;
      if (freq == -1)
        freq = c;
      else
        return false;
    }
    return true;
  }
}
