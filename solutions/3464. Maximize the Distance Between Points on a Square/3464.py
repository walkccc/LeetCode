from dataclasses import dataclass


@dataclass(frozen=True)
class Sequence:
  startX: int
  startY: int
  endX: int
  endY: int
  length: int

  def __iter__(self):
    yield self.startX
    yield self.startY
    yield self.endX
    yield self.endY
    yield self.length


class Solution:
  def maxDistance(self, side: int, points: list[list[int]], k: int) -> int:
    ordered = self._getOrderedPoints(side, points)

    def isValidDistance(m: int) -> bool:
      """
      Returns True if we can select `k` points such that the minimum Manhattan
      distance between any two consecutive chosen points is at least `m`.
      """
      dq = collections.deque([Sequence(*ordered[0], *ordered[0], 1)])
      maxLength = 1

      for i in range(1, len(ordered)):
        x, y = ordered[i]
        startX, startY = ordered[i]
        length = 1
        while dq and abs(x - dq[0].endX) + abs(y - dq[0].endY) >= m:
          if (abs(x - dq[0].startX) + abs(y - dq[0].startY) >= m
                  and dq[0].length + 1 >= length):
            startX = dq[0].startX
            startY = dq[0].startY
            length = dq[0].length + 1
            maxLength = max(maxLength, length)
          dq.popleft()
        dq.append(Sequence(startX, startY, x, y, length))

      return maxLength >= k

    l = 0
    r = side

    while l < r:
      m = (l + r + 1) // 2
      if isValidDistance(m):
        l = m
      else:
        r = m - 1

    return l

  def _getOrderedPoints(self, side: int, points: list[list[int]]) -> list[list[int]]:
    """
    Returns the ordered points on the perimeter of a square of side length
    `side`, starting from left, top, right, and bottom boundaries.
    """
    left = sorted([(x, y) for x, y in points if x == 0 and y > 0])
    top = sorted([(x, y) for x, y in points if x > 0 and y == side])
    right = sorted([(x, y) for x, y in points if x == side and y < side],
                   reverse=True)
    bottom = sorted([(x, y) for x, y in points if y == 0], reverse=True)
    return left + top + right + bottom
