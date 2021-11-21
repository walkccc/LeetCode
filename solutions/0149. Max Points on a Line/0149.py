class Solution:
  def maxPoints(self, points: List[List[int]]) -> int:
    ans = 0

    def gcd(a: int, b: int) -> int:
      return a if b == 0 else gcd(b, a % b)

    def getSlope(p1: List[int], p2: List[int]) -> Tuple[int, int]:
      dx = p2[0] - p1[0]
      dy = p2[1] - p1[1]
      if dx == 0:
        return (0, p1[0])
      if dy == 0:
        return (p1[1], 0)
      d = gcd(dx, dy)
      return (dx // d, dy // d)

    for i, p1 in enumerate(points):
      slopeCount = defaultdict(int)
      samePoints = 1
      maxPoints = 0
      for j in range(i + 1, len(points)):
        p2 = points[j]
        if p1 == p2:
          samePoints += 1
        else:
          slope = getSlope(p1, p2)
          slopeCount[slope] += 1
          maxPoints = max(maxPoints, slopeCount[slope])
      ans = max(ans, samePoints + maxPoints)

    return ans
