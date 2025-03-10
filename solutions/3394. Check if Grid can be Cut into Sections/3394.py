class Solution:
  def checkValidCuts(self, n: int, rectangles: list[list[int]]) -> bool:
    xs = [(startX, endX) for startX, _, endX, _ in rectangles]
    ys = [(startY, endY) for _, startY, _, endY in rectangles]
    return max(self._countMerged(xs),
               self._countMerged(ys)) >= 3

  def _countMerged(self, intervals: list[tuple[int, int]]) -> int:
    count = 0
    prevEnd = 0
    for start, end in sorted(intervals):
      if start < prevEnd:
        prevEnd = max(prevEnd, end)
      else:
        prevEnd = end
        count += 1
    return count
