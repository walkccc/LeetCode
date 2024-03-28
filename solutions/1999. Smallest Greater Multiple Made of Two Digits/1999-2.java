class Solution {
  public int findInteger(int k, int digit1, int digit2) {
    return findInteger(k, digit1, digit2, 0);
  }

  private int findInteger(int k, int d1, int d2, long x) {
    if (x > Integer.MAX_VALUE)
      return -1;
    if (x > k && x % k == 0)
      return (int) x;
    // Skip if d1/d2 and x are zero.
    final int a = (x + d1 == 0) ? -1 : findInteger(k, d1, d2, x * 10 + d1);
    final int b = (x + d2 == 0) ? -1 : findInteger(k, d1, d2, x * 10 + d2);
    if (a == -1)
      return b;
    if (b == -1)
      return a;
    return Math.min(a, b);
  }
}
