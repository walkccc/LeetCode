class Solution {
 public:
  int preimageSizeFZF(int k) {
    long l = 0;
    long r = 5L * k;

    while (l < r) {
      const long m = (l + r) / 2;
      if (trailingZeroes(m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return trailingZeroes(l) == k ? 5 : 0;
  }

 private:
  // 172. Factorial Trailing Zeroes
  int trailingZeroes(long n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};
