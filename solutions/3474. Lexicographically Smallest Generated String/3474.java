class Solution {
  public String generateString(String str1, String str2) {
    final int n = str1.length();
    final int m = str2.length();
    final int sz = n + m - 1;
    char[] ans = new char[sz];
    boolean[] modifiable = new boolean[sz];
    Arrays.fill(modifiable, true);

    // 1. Handle all 'T' positions first.
    for (int i = 0; i < n; ++i)
      if (str1.charAt(i) == 'T')
        for (int j = 0; j < m; ++j) {
          final int pos = i + j;
          if (ans[pos] != 0 && ans[pos] != str2.charAt(j))
            return "";
          ans[pos] = str2.charAt(j);
          modifiable[pos] = false;
        }

    // 2. Fill all remaining positions with 'a'.
    for (int i = 0; i < sz; ++i)
      if (ans[i] == 0)
        ans[i] = 'a';

    // 3. Handle all 'F' positions.
    for (int i = 0; i < n; ++i)
      if (str1.charAt(i) == 'F' && match(ans, i, str2)) {
        final int modifiablePos = lastModifiablePosition(i, m, modifiable);
        if (modifiablePos == -1)
          return "";
        ans[modifiablePos] = 'b';
        modifiable[modifiablePos] = false;
      }

    return new String(ans);
  }

  // Returns true if the substring of ans starting at `i` matches `s`.
  private boolean match(char[] ans, int i, String s) {
    for (int j = 0; j < s.length(); ++j)
      if (ans[i + j] != s.charAt(j))
        return false;
    return true;
  }

  // Finds the last modifiable position in the substring ans starting at `i`.
  private int lastModifiablePosition(int i, int m, boolean[] modifiable) {
    int modifiablePos = -1;
    for (int j = 0; j < m; ++j) {
      final int pos = i + j;
      if (modifiable[pos])
        modifiablePos = pos;
    }
    return modifiablePos;
  }
}
