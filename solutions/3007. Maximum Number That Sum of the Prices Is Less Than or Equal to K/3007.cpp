class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    long long l = 1;
    long long r = 1e15;

    while (l < r) {
      long long m = (l + r + 1) / 2;
      if (getSumPrices(m, x) > k)
        r = m - 1;
      else
        l = m;
    }

    return l;
  }

 private:
  // Returns the sum of prices of all numbers from 1 to `num`.
  long long getSumPrices(long long num, int x) {
    long long sumPrices = 0;
    // Increment `num` to account the 0-th row in the count of groups.
    ++num;
    for (int i = leftmostColumnIndex(num); i > 0; --i)
      // If the current column is valid, count the number of 1s in this column.
      if (i % x == 0) {
        const long long groupSize = 1LL << i;
        const long long halfGroupSize = 1LL << i - 1;
        sumPrices += num / groupSize * halfGroupSize;
        sumPrices += max(0LL, (num % groupSize) - halfGroupSize);
      }
    return sumPrices;
  }

  // Returns the leftmost column index in 1-indexed.
  int leftmostColumnIndex(long long num) {
    return 63 - __builtin_clzll(num) + 1;
  }
};
