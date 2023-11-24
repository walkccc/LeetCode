class Solution:
  def maxDistance(self, position: List[int], m: int) -> int:
    position.sort()

    l = 1
    r = position[-1] - position[0]

    def numBalls(force: int) -> int:
      balls = 0
      prevPosition = -force
      for pos in position:
        if pos - prevPosition >= force:
          balls += 1
          prevPosition = pos
      return balls

    while l < r:
      mid = r - (r - l) // 2
      if numBalls(mid) >= m:
        l = mid
      else:
        r = mid - 1

    return l
