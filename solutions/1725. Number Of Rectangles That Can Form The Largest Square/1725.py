class Solution:
  def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
    minSides = [min(x, y) for x, y in rectangles]
    return minSides.count(max(minSides))
