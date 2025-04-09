class Solution {
 public:
  int maxSizedArray(long long s) {
    if (s == 0)
      return 1;

    int l = 0;
    int r = 1196;  // when s = 10^15, n = 1196

    while (l < r) {
      const int m = (l + r + 1) / 2;
      if (getArraySum(m) <= s)
        l = m;
      else
        r = m - 1;
    }

    return l;
  }

 private:
  // Returns the number of integers in [0, n - 1] with the i-th bit set.
  //
  // For the i-th bit, numbers in the range [0, n - 1] can be divided into
  // groups of 2^(i + 1) numbers. In each group, exactly half of the numbers
  // have the i-th bit set.
  int getNumbersWithBitSet(int n, int i) {
    const int groupSize = 1 << (i + 1);
    const int halfGroupSize = 1 << i;
    const int fullGroups = n / groupSize;
    const int remaining = max(0, (n % groupSize) - halfGroupSize);
    return fullGroups * halfGroupSize + remaining;
  }

  // Returns the sum of all i * (j OR k) values in 3D arrays of size n^3.
  //
  //   sum(i * (j OR k)), where 0 <= i, j, k < n
  // = 0 * (j OR k) + 1 * (j OR k) + ... + (n - 1) * (j OR k)
  // = (0 + 1 + ... + n - 1) * sum(j OR k)
  // = (n * (n - 1) / 2) * sum(j OR k)
  long getArraySum(int n) {
    const int arithmeticSum = n * (n - 1) / 2;
    long orSum = 0;
    for (int i = 0; i < bitLength(n); ++i) {
      const int numbersWituoutBit = n - getNumbersWithBitSet(n, i);
      const int pairsWithBit =
          (n * n) - (numbersWituoutBit * numbersWituoutBit);
      orSum += pairsWithBit * (1L << i);
    }
    return arithmeticSum * orSum;
  }

  int bitLength(int n) {
    return 32 - __builtin_clz(n);
  }
};
