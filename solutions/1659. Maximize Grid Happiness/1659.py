class Solution:
  def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
    def getPlacementCost(i: int, j: int, inMask: int, exMask: int, diff: int) -> int:
      """Calculates the cost based on left and up neighbors.

      The `diff` parameter represents the happiness change due to the current
      placed person in (i, j). We add `diff` each time we encounter a neighbor
      (left or up) who is already placed.

      Case 1: If the neighbor is an introvert, we subtract 30 from cost.
      Case 2: If the neighbor is an extrovert, we add 20 to from cost.
      """
      cost = 0
      if i > 0:
        if (1 << (n - 1)) & inMask:
          cost += diff - 30
        if (1 << (n - 1)) & exMask:
          cost += diff + 20
      if j > 0:
        if 1 & inMask:
          cost += diff - 30
        if 1 & exMask:
          cost += diff + 20
      return cost

    @functools.lru_cache(None)
    def dp(pos: int, inMask: int, exMask: int, inCount: int, exCount: int) -> int:
      # `inMask` is the placement of introvert people in the last n cells.
      # e.g. if we have m = 2, n = 3, i = 1, j = 1, then inMask = 0b101 means
      #
      # ? 1 0
      # 1 x ? (x := current position)
      i, j = divmod(pos, n)
      if i == m:
        return 0

      shiftedInMask = (inMask << 1) & ((1 << n) - 1)
      shiftedExMask = (exMask << 1) & ((1 << n) - 1)

      skip = dp(pos + 1, shiftedInMask, shiftedExMask, inCount, exCount)
      placeIntrovert = 120 + getPlacementCost(i, j, inMask, exMask, -30) + \
          dp(pos + 1, shiftedInMask + 1, shiftedExMask, inCount - 1, exCount) if inCount > 0 \
          else -math.inf
      placeExtrovert = 40 + getPlacementCost(i, j, inMask, exMask, 20) + \
          dp(pos + 1, shiftedInMask, shiftedExMask + 1, inCount, exCount - 1) if exCount > 0 \
          else -math.inf
      return max(skip, placeIntrovert, placeExtrovert)

    return dp(0, 0, 0, introvertsCount, extrovertsCount)
