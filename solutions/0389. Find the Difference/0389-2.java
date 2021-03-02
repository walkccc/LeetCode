class Solution {
  public char findTheDifference(String s, String t) {
    int[] count = new int[128];

    for (final char c : s.toCharArray())
      ++count[c];

    for (final char c : t.toCharArray())
      if (--count[c] < 0)
        return c;

    throw new IllegalArgumentException();
  }
}
