class Solution {
  public boolean backspaceCompare(final String S, final String T) {
    for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0; --i, --j) {
      for (int backspace = 0; i >= 0 && (S.charAt(i) == '#' || backspace > 0); --i)
        backspace += S.charAt(i) == '#' ? 1 : -1;
      for (int backspace = 0; j >= 0 && (T.charAt(j) == '#' || backspace > 0); --j)
        backspace += T.charAt(j) == '#' ? 1 : -1;
      if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j))
        return false;
      if (i < 0 && j >= 0 && T.charAt(j) != '#')
        return false;
      if (j < 0 && i >= 0 && S.charAt(i) != '#')
        return false;
    }

    return true;
  }
}