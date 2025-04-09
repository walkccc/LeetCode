class Solution:
  def minRectanglesToCoverPoints(self, points: list[list[int]], w: int) -> int:
    ans = 0
    prevX = -w - 1
    xs = sorted([x for x, _ in points])

    for x in xs:
      if x > prevX + w:
        ans += 1
        prevX = x

    return ans
