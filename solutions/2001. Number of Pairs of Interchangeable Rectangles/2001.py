class Solution:
  def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
    ratioCount = collections.Counter()

    for width, height in rectangles:
      ratioCount[width / height] += 1

    return sum(c * (c - 1) // 2 for c in ratioCount.values())
