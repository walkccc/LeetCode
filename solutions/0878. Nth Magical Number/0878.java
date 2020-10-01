class Solution {
  public int nthMagicalNumber(long N, long A, long B) {
    final long kMod = (long) 1e9 + 7;

    long lcm = A * B / gcd(A, B);
    long l = Math.min(A, B);
    long r = Math.min(A, B) * N;

    while (l < r) {
      long m = l + (r - l) / 2;
      if (m / A + m / B - m / lcm < N)
        l = m + 1;
      else
        r = m;
    }

    return (int) (l % kMod);
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}