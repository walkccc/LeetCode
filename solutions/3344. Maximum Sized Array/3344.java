class Solution {
  public int maxSizedArray(long s) {
    if (s == 0)
      return 1;

    int l = 0;
    int r = 1196; // when s = 10^15, n = 1196

    while (l < r) {
      final int m = (l + r + 1) / 2;
      if (getArraySum(m) <= s)
        l = m;
      else
        r = m - 1;
    }

    return l;
  }

  // Returns the number of integers in [0, n - 1] with the i-th bit set.
  //
  // For the i-th bit, numbers in the range [0, n - 1] can be divided into
  // groups of 2^(i + 1) numbers. In each group, exactly half of the numbers
  // have the i-th bit set.
  private int getNumbersWithBitSet(int n, int i) {
    final int groupSize = 1 << (i + 1);
    final int halfGroupSize = 1 << i;
    final int fullGroups = n / groupSize;
    final int remaining = Math.max(0, (n % groupSize) - halfGroupSize);
    return fullGroups * halfGroupSize + remaining;
  }

  // Returns the sum of all i * (j OR k) values in 3D arrays of size n^3.
  //
  //   sum(i * (j OR k)), where 0 <= i, j, k < n
  // = 0 * (j OR k) + 1 * (j OR k) + ... + (n - 1) * (j OR k)
  // = (0 + 1 + ... + n - 1) * sum(j OR k)
  // = (n * (n - 1) / 2) * sum(j OR k)
  private long getArraySum(int n) {
    final int arithmeticSum = n * (n - 1) / 2;
    long orSum = 0;
    for (int i = 0; i < bitLength(n); i++) {
      int numbersWithoutBit = n - getNumbersWithBitSet(n, i);
      long pairsWithBit = (long) n * n - (long) numbersWithoutBit * numbersWithoutBit;
      orSum += pairsWithBit * (1L << i);
    }
    return arithmeticSum * orSum;
  }

  private int bitLength(int n) {
    return 32 - Integer.numberOfLeadingZeros(n);
  }
}
