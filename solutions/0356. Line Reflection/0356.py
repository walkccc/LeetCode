class Solution:
  def isReflected(self, points: List[List[int]]) -> bool:
    minX = math.inf
    maxX = -math.inf
    seen = set()

    for x, y in points:
      minX = min(minX, x)
      maxX = max(maxX, x)
      seen.add((x, y))

    summ = minX + maxX
    # (leftX + rightX) / 2 = (minX + maxX) / 2
    #  leftX = minX + maxX - rightX
    # rightX = minX + maxX - leftX

    return all((summ - x, y) in seen for x, y in points)
