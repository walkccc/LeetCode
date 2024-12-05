class Solution:
  def countGoodRectangles(self, rectangles: list[list[int]]) -> int:
    minSides = [min(x, y) for x, y in rectangles]
    return minSides.count(max(minSides))
