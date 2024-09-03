class Solution:
  def maxArea(
      self,
      h: int,
      w: int,
      horizontalCuts: list[int],
      verticalCuts: list[int],
  ) -> int:
    kMod = 1_000_000_007
    # the maximum gap of each direction
    maxGapX = max(b - a
                  for a, b in itertools.pairwise(
                      [0] + sorted(horizontalCuts) + [h]))
    maxGapY = max(b - a
                  for a, b in itertools.pairwise(
                      [0] + sorted(verticalCuts) + [w]))
    return maxGapX * maxGapY % kMod
