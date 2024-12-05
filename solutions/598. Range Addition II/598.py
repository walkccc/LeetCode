class Solution:
  def maxCount(self, m: int, n: int, ops: list[list[int]]) -> int:
    minY = m
    minX = n

    for y, x in ops:
      minY = min(minY, y)
      minX = min(minX, x)

    return minX * minY
