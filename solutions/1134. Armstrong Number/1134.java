class Solution {
  public boolean isArmstrong(int n) {
    final String s = String.valueOf(n);
    final int k = s.length();
    for (final char c : s.toCharArray())
      n -= Math.pow(c - '0', k);
    return n == 0;
  }
}
