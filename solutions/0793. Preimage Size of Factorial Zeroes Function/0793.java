class Solution {
  public int preimageSizeFZF(int k) {
    long l = 0;
    long r = 5 * (long) k;

    while (l < r) {
      final long m = (l + r) / 2;
      if (trailingZeroes(m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return trailingZeroes(l) == k ? 5 : 0;
  }

  // 172. Factorial Trailing Zeroes
  private int trailingZeroes(long n) {
    return n == 0 ? 0 : (int) (n / 5 + trailingZeroes(n / 5));
  }
}
