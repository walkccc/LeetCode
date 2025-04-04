FACTOR_COUNTS = {
    0: collections.Counter(),
    1: collections.Counter(),
    2: collections.Counter([2]),
    3: collections.Counter([3]),
    4: collections.Counter([2, 2]),
    5: collections.Counter([5]),
    6: collections.Counter([2, 3]),
    7: collections.Counter([7]),
    8: collections.Counter([2, 2, 2]),
    9: collections.Counter([3, 3]),
}


class Solution:
  def smallestNumber(self, num: str, t: int) -> str:
    primeCount, isDivisible = self._getPrimeCount(t)
    if not isDivisible:
      return '-1'

    factorCount = self._getFactorCount(primeCount)
    if sum(factorCount.values()) > len(num):
      return ''.join(factor * freq for factor, freq in factorCount.items())

    primeCountPrefix = sum((FACTOR_COUNTS[int(c)]
                            for c in num), start=collections.Counter())
    firstZeroIndex = next((i for i, d in enumerate(num) if d == '0'), len(num))
    if firstZeroIndex == len(num) and primeCount <= primeCountPrefix:
      return num

    for i, c in reversed(list(enumerate(num))):
      d = int(c)
      # Remove the current digit's factors from primeCountPrefix.
      primeCountPrefix -= FACTOR_COUNTS[d]
      spaceAfterThisDigit = len(num) - 1 - i
      if i <= firstZeroIndex:
        for biggerDigit in range(d + 1, 10):
          # Compute the required factors after replacing with a larger digit.
          factorsAfterReplacement = self._getFactorCount(
              primeCount - primeCountPrefix - FACTOR_COUNTS[biggerDigit]
          )
          # Check if the replacement is possible within the available space.
          if sum(factorsAfterReplacement.values()) <= spaceAfterThisDigit:
            # Fill extra space with '1', if any, and construct the result.
            fillOnes = spaceAfterThisDigit - sum(
                factorsAfterReplacement.values())
            return (
                num[:i]  # Keep the prefix unchanged.
                + str(biggerDigit)  # Replace the current digit.
                + '1' * fillOnes  # Fill remaining space with '1'.
                + ''.join(factor * freq for factor,
                          freq in factorsAfterReplacement.items())
            )

    # No solution of the same length exists, so we need to extend the number
    # by prepending '1's and adding the required factors.
    factorCount = self._getFactorCount(primeCount)
    return (
        '1' * (len(num) + 1 - sum(factorCount.values()))
        + ''.join(factor * freq for factor, freq in factorCount.items())
    )

  def _getPrimeCount(self, t: int) -> tuple[dict[int, int], bool]:
    """
    Returns the count of prime factors of t and if t is divisible by 2, 3, 5, 7.
    """
    count = collections.Counter()
    for prime in [2, 3, 5, 7]:
      while t % prime == 0:
        t //= prime
        count[prime] += 1
    return count, t == 1

  def _getFactorCount(self, count: dict[int, int]) -> dict[str, int]:
    """Returns the required factors to form the smallest number."""
    count8, remaining2 = divmod(count[2], 3)  # 2^3 = 8
    count9, count3 = divmod(count[3], 2)  # 3^2 = 9
    count4, count2 = divmod(remaining2, 2)  # 2^2 = 4
    # Combine 2 and 3 to 6 if both are present.
    count2, count3, count6 = ((0, 0, 1) if count2 == 1 and count3 == 1
                              else (count2, count3, 0))
    # Combine 3 and 4 to 2 and 6 if both are present.
    count2, count6, count3, count4 = ((1, 1, 0, 0)
                                      if count3 == 1 and count4 == 1
                                      else (count2, count6, count3, count4))
    return {'2': count2, '3': count3, '4': count4, '5': count[5],
            '6': count6, '7': count[7], '8': count8, '9': count9}
