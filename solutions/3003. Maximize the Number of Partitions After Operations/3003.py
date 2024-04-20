class Solution:
  def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
    @functools.lru_cache(None)
    def dp(i: int, canChange: bool, mask: int) -> int:
      """
      Returns the maximum number of partitions of s[i..n), where `canChange` is
      True if we can still change a letter, and `mask` is the bitmask of the
      letters we've seen.
      """
      if i == len(s):
        return 0

      def getRes(newBit: int, nextCanChange: bool) -> int:
        nextMask = mask | newBit
        if nextMask.bit_count() > k:
          return 1 + dp(i + 1, nextCanChange, newBit)
        return dp(i + 1, nextCanChange, nextMask)

      # Initialize the result based on the current letter.
      res = getRes(1 << (ord(s[i]) - ord('a')), canChange)

      # If allowed, explore the option to change the current letter.
      if canChange:
        for j in range(26):
          res = max(res, getRes(1 << j, False))
      return res

    return dp(0, True, 0) + 1
