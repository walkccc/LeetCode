class Solution {
  public boolean isOneEditDistance(String s, String t) {
    final int m = s.length();
    final int n = t.length();
    if (m > n) // Make sure that |s| <= |t|.
      return isOneEditDistance(t, s);

    for (int i = 0; i < m; ++i)
      if (s.charAt(i) != t.charAt(i)) {
        if (m == n)
          return s.substring(i + 1).equals(t.substring(i + 1)); // Replace s[i] with t[i].
        return s.substring(i).equals(t.substring(i + 1));       // Delete t[i].
      }

    return m + 1 == n; // Delete t[-1].
  }
}
