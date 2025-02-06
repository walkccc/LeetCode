class Solution {
 public:
  int distanceSum(int m, int n, int k) {
    // For each distance d, where 1 < d < m, there are `m - d` ways to choose
    // the two columns that the two pieces are on. For each of the two pieces,
    // there are `n` ways to choose the row that the piece is on.
    // Therefore, the contribution of row differences is
    //   sum(d * (m - d) * n^2), where 1 < d <= m - 1
    // = n^2 * sum(d * m - d^2)
    // = n^2 * (d * m * (m - 1) / 2 - m * (m - 1) * (2m - 1) / 6)
    // = n^2 * (m^3 - m) / 6
    // Similarly, the contribution of column differences is
    //   m^2 * (n^3 - n) / 6
    const int rowContrib = 1L * n * n * (1L * m * m * m - m) / 6 % kMod;
    const int colContrib = 1L * m * m * (1L * n * n * n - n) / 6 % kMod;
    return (rowContrib + colContrib) * nCk(m * n - 2, k - 2) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      // By Fermat's little theorem.
      res = res * (n - i + 1) % kMod * modPow(i, kMod - 2) % kMod;
    return res;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
