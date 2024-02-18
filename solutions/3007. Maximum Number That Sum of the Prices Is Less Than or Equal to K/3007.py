class Solution:
  def findMaximumNumber(self, k: int, x: int) -> int:
    def getSumPrices(num: int) -> int:
      """Returns the sum of prices of all numbers from 1 to `num`."""
      sumPrices = 0
      # Increment `num` to account the 0-th row in the count of groups.
      num += 1
      for i in range(num.bit_length(), 0, -1):
        if i % x == 0:
          groupSize = 1 << i
          halfGroupSize = 1 << i - 1
          sumPrices += num // groupSize * halfGroupSize
          sumPrices += max(0, (num % groupSize) - halfGroupSize)
      return sumPrices

    return bisect.bisect_right(range(1, 10**15), k,
                               key=lambda m: getSumPrices(m))
