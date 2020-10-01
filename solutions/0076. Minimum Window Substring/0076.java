class Solution {
  public String minWindow(String s, String t) {
    int[] count = new int[128];
    int required = t.length();
    int bestLeft = -1;
    int minLength = Integer.MAX_VALUE;

    for (final char c : t.toCharArray())
      ++count[c];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (--count[s.charAt(r)] >= 0)
        --required;
      while (required == 0) {
        if (r - l + 1 < minLength) {
          bestLeft = l;
          minLength = r - l + 1;
        }
        if (++count[s.charAt(l++)] > 0)
          ++required;
      }
    }

    return minLength == Integer.MAX_VALUE ? "" : s.substring(bestLeft, bestLeft + minLength);
  }
}