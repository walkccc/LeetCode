class Solution {
  public int minStartingIndex(String s, String pattern) {
    int[] z1 = zFunction(new StringBuilder(pattern).append(s).toString());
    int[] z2 = zFunction(new StringBuilder(pattern)
                             .reverse() //
                             .append(new StringBuilder(s).reverse())
                             .toString());

    // Match s[i..i + len(pattern) - 1] with `pattern` from both the prefix and
    // the suffix.
    for (int i = 0; i <= s.length() - pattern.length(); ++i)
      if (z1[pattern.length() + i] + z2[s.length() - i] >= pattern.length() - 1)
        return i;

    return -1;
  }

  // Returns the z array, where z[i] is the length of the longest prefix of
  // s[i..n) which is also a prefix of s.
  //
  // https://cp-algorithms.com/string/z-function.html#implementation
  private int[] zFunction(final String s) {
    final int n = s.length();
    int[] z = new int[n];
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
      if (i < r)
        z[i] = Math.min(r - i, z[i - l]);
      while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }

  private String reversed(String s) {
    return new StringBuilder(s).reverse().toString();
  }
}
