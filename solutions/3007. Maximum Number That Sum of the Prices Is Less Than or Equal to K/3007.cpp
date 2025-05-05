class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    long l = 1;
    long r = 1e15;

    while (l < r) {
      const long m = (l + r + 1) / 2;
      if (getSumPrices(m, x) <= k)
        l = m;
      else
        r = m - 1;
    }

    return l;
  }

 private:
  // Returns the sum of prices of all numbers from 1 to `num`.
  long getSumPrices(long num, int x) {
    long sumPrices = 0;
    // Increment `num` to account the 0-th row in the count of groups.
    ++num;
    for (int i = std::bit_width(static_cast<unsigned long>(num)); i > 0; --i)
      // If the current column is valid, count the number of 1s in this column.
      if (i % x == 0) {
        const long groupSize = 1L << i;
        const long halfGroupSize = 1L << i - 1;
        sumPrices += num / groupSize * halfGroupSize;
        sumPrices += max(0L, (num % groupSize) - halfGroupSize);
      }
    return sumPrices;
  }
};
