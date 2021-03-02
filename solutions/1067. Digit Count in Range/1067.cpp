class Solution {
 public:
  int digitsCount(int d, int low, int high) {
    return countDigit(high, d) - countDigit(low - 1, d);
  }

 private:
  int countDigit(int n, int d) {
    int count = 0;

    for (int pow10 = 1; pow10 <= n; pow10 *= 10) {
      const int divisor = pow10 * 10;
      const int quotient = n / divisor;
      const int remainder = n % divisor;

      if (quotient > 0)
        count += quotient * pow10;
      if (d == 0)
        count -= pow10;
      if (remainder >= d * pow10)
        count += min(remainder - d * pow10 + 1, pow10);
    }

    return count;
  }
};
