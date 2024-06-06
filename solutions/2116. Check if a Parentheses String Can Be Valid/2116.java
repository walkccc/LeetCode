class Solution {
  public boolean canBeValid(String s, String locked) {
    if (s.length() % 2 == 1)
      return false;

    return check(s, locked, true) && check(new StringBuilder(s).reverse().toString(),
                                           new StringBuilder(locked).reverse().toString(), false);
  }

  private boolean check(final String s, final String locked, boolean isForward) {
    int changeable = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      final char lock = locked.charAt(i);
      if (lock == '0')
        ++changeable;
      else if (c == '(')
        ++l;
      else // c == ')'
        ++r;
      if (isForward && changeable + l - r < 0)
        return false;
      if (!isForward && changeable + r - l < 0)
        return false;
    }

    return true;
  }
}
