class Solution {
  public boolean splitString(String s) {
    return isValid(s, 0, -1, 0);
  }

  private boolean isValid(final String s, int start, long prev, int segment) {
    if (start == s.length() && segment > 1)
      return true;

    long curr = 0;
    for (int i = start; i < s.length(); ++i) {
      curr = curr * 10 + s.charAt(i) - '0';
      if (curr > 9999999999)
        return false;
      if ((prev == -1 || curr == prev - 1) && isValid(s, i + 1, curr, segment + 1))
        return true;
    }

    return false;
  }
}
