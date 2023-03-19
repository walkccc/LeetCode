class Solution {
  public boolean isAnagram(String s, String t) {
    if (s.length() != t.length())
      return false;

    int[] count = new int[128];

    for (final char c : s.toCharArray())
      ++count[c];

    for (final char c : t.toCharArray())
      if (--count[c] < 0)
        return false;

    return true;
  }
}
