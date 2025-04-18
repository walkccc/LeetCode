class Solution {
  public int countDigitOne(int n) {
    int ans = 0;

    for (long pow10 = 1; pow10 <= n; pow10 *= 10) {
      final long divisor = pow10 * 10;
      final int quotient = (int) (n / divisor);
      final int remainder = (int) (n % divisor);
      if (quotient > 0)
        ans += quotient * pow10;
      if (remainder >= pow10)
        ans += Math.min(remainder - pow10 + 1, pow10);
    }

    return ans;
  }
}
