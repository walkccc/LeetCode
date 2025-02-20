class Solution {
  public boolean checkIfCanBreak(String s1, String s2) {
    int[] count1 = new int[26];
    int[] count2 = new int[26];

    for (final char c : s1.toCharArray())
      ++count1[c - 'a'];

    for (final char c : s2.toCharArray())
      ++count2[c - 'a'];

    return canBreak(count1, count2) || canBreak(count2, count1);
  }

  // Returns true if count1 can break count2.
  private boolean canBreak(int[] count1, int[] count2) {
    int diff = 0;
    for (int i = 0; i < 26; ++i) {
      diff += count2[i] - count1[i];
      // count2 is alphabetically greater than count1.
      if (diff < 0)
        return false;
    }
    return true;
  }
}
