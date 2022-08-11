class Solution {
  public boolean isOneEditDistance(String s, String t) {
    final int m = s.length();
    final int n = t.length();
    if (m > n) // make sure len(s) <= len(t)
      return isOneEditDistance(t, s);

    for (int i = 0; i < m; ++i)
      if (s.charAt(i) != t.charAt(i)) {
        if (m == n)
          return s.substring(i + 1).equals(t.substring(i + 1)); // replace s[i] with t[i]
        return s.substring(i).equals(t.substring(i + 1));       // delete t[i]
      }

    return m + 1 == n; // delete t[-1]
  }
}
