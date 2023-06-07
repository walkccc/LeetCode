class Solution:
  def squareFreeSubsets(self, nums: List[int]) -> int:
    kMod = 1_000_000_007
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

    # E.g. num = 10 = 2 * 5, so mask = (101)2 . (1010)2 (append a 0)
    #      num = 15 = 3 * 5, so mask = (110)2 . (1100)2 (append a 0)
    #      num = 25 = 5 * 5, so mask =  (-1)2 . (1..1)2 (invalid)
    def getMask(num: int) -> int:
      mask = 0
      for i, prime in enumerate(primes):
        rootCount = 0
        while num % prime == 0:
          num //= prime
          rootCount += 1
        if rootCount >= 2:
          return -1
        if rootCount == 1:
          mask |= 1 << i
      return mask << 1

    masks = [getMask(num) for num in nums]

    @functools.lru_cache(None)
    def dp(i: int, usedMask: int) -> int:
      if i == len(masks):
        return 1
      pick = dp(i + 1, usedMask | masks[i]) \
          if (masks[i] & usedMask) == 0 else 0
      skip = dp(i + 1, usedMask)
      return (pick + skip) % kMod

    # -1 means that we take no number.
    # `usedMask` is initialized to 1 so that -1 & 1 = 1 instead of 0.
    return dp(0, 1) - 1
