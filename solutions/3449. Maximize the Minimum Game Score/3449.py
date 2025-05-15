class Solution:
  def maxScore(self, points: list[int], m: int) -> int:
    def isPossible(minVal: int, m: int) -> bool:
      """
      Returns True if it is possible to achieve the maximum minimum value `x`
      with `m` number of moves.
      """
      moves = 0
      prevMoves = 0  # to track remaining moves from the previous point
      for i, point in enumerate(points):
        required = (minVal + point - 1) // point  # ceil(minVal / point)
        required = max(0, required - prevMoves)
        if required > 0:
          moves += 2 * required - 1
          prevMoves = required - 1
        elif i + 1 < len(points):
          moves += 1
          prevMoves = 0
        if moves > m:
          return False
      return True

    l = 0
    r = (m + 1) // 2 * points[0] + 1

    while l < r:
      mid = (l + r + 1) // 2
      if isPossible(mid, m):
        l = mid
      else:
        r = mid - 1

    return l
