class Solution {
  public int preimageSizeFZF(int K) {
    long l = 0;
    long r = 5 * (long) K;

    while (l < r) {
      final long m = l + (r - l) / 2;
      if (trailingZeroes(m) >= K)
        r = m;
      else
        l = m + 1;
    }

    return trailingZeroes(l) == K ? 5 : 0;
  }

  // 172. Factorial Trailing Zeroes
  private int trailingZeroes(long n) {
    return n == 0 ? 0 : (int) (n / 5 + trailingZeroes(n / 5));
  }
}
