class Solution:
  def gcdValues(self, nums: list[int], queries: list[int]) -> list[int]:
    maxNum = max(nums)
    # countDivisor[d] := the number of `nums` having `num % d == 0`
    countDivisor = [0] * (maxNum + 1)
    # countGcdPair[g] := the number of pairs having gcd == g
    countGcdPair = [0] * (maxNum + 1)

    for num in nums:
      for i in range(1, math.isqrt(num) + 1):
        if num % i == 0:
          countDivisor[i] += 1
          if i != num // i:
            countDivisor[num // i] += 1

    for gcd in range(maxNum, 0, -1):
      # There are C(countDivisor[gcd], 2) pairs that have a common divisor
      # that's a multiple of `gcd` (including the one that equals to `gcd`).
      # So, substract the multiples of `gcd` to have the number of pairs with a
      # gcd that's exactly `gcd`.
      countGcdPair[gcd] = countDivisor[gcd] * (countDivisor[gcd] - 1) // 2
      for largerGcd in range(2 * gcd, maxNum + 1, gcd):
        countGcdPair[gcd] -= countGcdPair[largerGcd]

    # prefixCountGcdPair[g] := the number of pairs having gcd <= g
    prefixCountGcdPair = list(itertools.accumulate(countGcdPair))
    return [bisect.bisect_left(prefixCountGcdPair, query + 1)
            for query in queries]
