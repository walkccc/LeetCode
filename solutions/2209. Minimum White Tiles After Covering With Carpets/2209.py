class Solution:
  def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
    kMax = 1000

    # dp(i, j) := min # of visible white tiles of floor[i:]
    # after covering at most j carpets
    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      if j < 0:
        return kMax
      if i >= len(floor):
        return 0
      return min(dp(i + carpetLen, j - 1),
                 dp(i + 1, j) + int(floor[i]))

    return dp(0, numCarpets)
