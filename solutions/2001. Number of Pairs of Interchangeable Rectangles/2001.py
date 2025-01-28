class Solution:
  def interchangeableRectangles(self, rectangles: list[list[int]]) -> int:
    ratioCount = collections.Counter()

    for width, height in rectangles:
      ratioCount[width / height] += 1

    return sum(count * (count - 1) // 2
               for count in ratioCount.values())
