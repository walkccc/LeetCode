class Solution:
  def largestSquareArea(
      self,
      bottomLeft: list[list[int]],
      topRight: list[list[int]],
  ) -> int:
    minSide = 0

    for ((ax1, ay1), (ax2, ay2)), ((bx1, by1), (bx2, by2)) in (
            itertools.combinations(zip(bottomLeft, topRight), 2)):
      overlapX = min(ax2, bx2) - max(ax1, bx1)
      overlapY = min(ay2, by2) - max(ay1, by1)
      minSide = max(minSide, min(overlapX, overlapY))

    return minSide**2
