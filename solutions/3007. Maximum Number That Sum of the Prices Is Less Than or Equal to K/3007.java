class Solution {
  public long findMaximumNumber(long k, int x) {
    long l = 1;
    long r = 1000000000000000L;

    while (l < r) {
      final long m = (l + r + 1) / 2;
      if (getSumPrices(m, x) > k)
        r = m - 1;
      else
        l = m;
    }

    return l;
  }

  // Returns the sum of prices of all numbers from 1 to `num`.
  private long getSumPrices(long num, int x) {
    long sumPrices = 0;
    num++; // Increment `num` to account the 0-th row in the count of groups.
    for (int i = leftmostColumnIndex(num); i > 0; --i)
      if (i % x == 0) {
        final long groupSize = 1L << i;
        final long halfGroupSize = 1L << i - 1;
        sumPrices += num / groupSize * halfGroupSize;
        sumPrices += Math.max(0L, (num % groupSize) - halfGroupSize);
      }
    return sumPrices;
  }

  // Returns the leftmost column index in 1-indexed.
  private int leftmostColumnIndex(long num) {
    return 63 - Long.numberOfLeadingZeros(num) + 1;
  }
}
