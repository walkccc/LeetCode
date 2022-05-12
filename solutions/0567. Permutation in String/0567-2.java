class Solution {
  public boolean checkInclusion(String s1, String s2) {
    int[] count = new int[128];
    int required = s1.length();

    for (final char c : s1.toCharArray())
      ++count[c];

    for (int r = 0; r < s2.length(); ++r) {
      if (--count[s2.charAt(r)] >= 0)
        --required;
      if (r >= s1.length()) // the window is oversized
        if (++count[s2.charAt(r - s1.length())] > 0)
          ++required;
      if (required == 0)
        return true;
    }

    return false;
  }
}
