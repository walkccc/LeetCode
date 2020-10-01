class Solution {
  public int myAtoi(String s) {
    s = s.strip();
    if (s.isEmpty())
      return 0;

    long ans = 0;
    final boolean isNegative = s.charAt(0) == '-';

    if (s.charAt(0) == '-' || s.charAt(0) == '+')
      s = s.substring(1);

    for (final char c : s.toCharArray()) {
      if (!Character.isDigit(c))
        break;
      ans = ans * 10 + (c - '0');
      if (isNegative && -ans <= Integer.MIN_VALUE)
        return Integer.MIN_VALUE;
      if (!isNegative && ans >= Integer.MAX_VALUE)
        return Integer.MAX_VALUE;
    }

    return isNegative ? (int) -ans : (int) ans;
  }
}