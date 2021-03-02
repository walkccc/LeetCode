class Solution {
 public:
  int preimageSizeFZF(int K) {
    long l = 0;
    long r = 5 * (long)K;

    while (l < r) {
      const long m = l + (r - l) / 2;
      if (trailingZeroes(m) >= K)
        r = m;
      else
        l = m + 1;
    }

    return trailingZeroes(l) == K ? 5 : 0;
  }

 private:
  // 172. Factorial Trailing Zeroes
  int trailingZeroes(long n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};
