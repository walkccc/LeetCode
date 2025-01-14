class Solution {
 public:
  int divide(int dividend, int divisor) {
    // -2^{31} / -1 = 2^31 will overflow, so return 2^31 - 1.
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;

    const int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    long ans = 0;
    long dvd = labs(dividend);
    long dvs = labs(divisor);

    while (dvd >= dvs) {
      long k = 1;
      while (k * 2 * dvs <= dvd)
        k *= 2;
      dvd -= k * dvs;
      ans += k;
    }

    return sign * ans;
  }
};
