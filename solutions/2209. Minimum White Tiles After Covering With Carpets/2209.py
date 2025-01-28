class Solution:
  def minimumWhiteTiles(
      self,
      floor: str,
      numCarpets: int,
      carpetLen: int,
  ) -> int:
    kMax = 1000

    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """
      Returns the minimum number of visible white tiles of floor[i..n) after
      covering at most j carpets.
      """
      if j < 0:
        return kMax
      if i >= len(floor):
        return 0
      return min(dp(i + carpetLen, j - 1),
                 dp(i + 1, j) + int(floor[i]))

    return dp(0, numCarpets)
