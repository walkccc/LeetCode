class Solution {
  public int countSubstrings(String s, String t) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i)
      ans += count(s, t, i, 0);

    for (int j = 1; j < t.length(); ++j)
      ans += count(s, t, 0, j);

    return ans;
  }

  // Returns the # of substrings of s[i:] and t[j:] that differ by one char.
  private int count(final String s, final String t, int i, int j) {
    int res = 0;
    // # of substrings starting at s[i] and t[j] ending at the current index
    // with zero different chars.
    int dp0 = 0;
    // # of substrings starting at s[i] and t[j] ending at the current index
    // with one different char.
    int dp1 = 0;

    for (; i < s.length() && j < t.length(); ++i, ++j) {
      if (s.charAt(i) == t.charAt(j)) {
        ++dp0;
      } else {
        dp1 = dp0 + 1;
        dp0 = 0;
      }
      res += dp1;
    }

    return res;
  }
}
