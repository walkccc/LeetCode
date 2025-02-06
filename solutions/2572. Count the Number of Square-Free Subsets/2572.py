class Solution:
  def squareFreeSubsets(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

    def getMask(num: int) -> int:
      """
      e.g. num = 10 = 2 * 5, so mask = 0b101 . 0b1010 (append a 0)
           num = 15 = 3 * 5, so mask = 0b110 . 0b1100 (append a 0)
           num = 25 = 5 * 5, so mask =  (-1)2 . (1..1)2 (invalid)
      """
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
    def dp(i: int, used: int) -> int:
      if i == len(masks):
        return 1
      pick = dp(i + 1, used | masks[i]) if (masks[i] & used) == 0 else 0
      skip = dp(i + 1, used)
      return (pick + skip) % kMod

    # -1 means that we take no number.
    # `used` is initialized to 1 so that -1 & 1 = 1 instead of 0.
    return (dp(0, 1) - 1 + kMod) % kMod
