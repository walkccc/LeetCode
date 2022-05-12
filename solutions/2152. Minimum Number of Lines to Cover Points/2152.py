class Solution:
  def minimumLines(self, points: List[List[int]]) -> int:
    n = len(points)
    allCovered = (1 << n) - 1
    maxLines = n // 2 + (n & 1)

    def getSlope(i: int, j: int) -> Tuple[int, int]:
      dx = points[i][0] - points[j][0]
      dy = points[i][1] - points[j][1]
      if dx == 0:
        return (0, points[i][0])
      if dy == 0:
        return (points[i][1], 0)
      d = gcd(dx, dy)
      x, y = dx // d, dy // d
      return (x, y) if x > 0 else (-x, -y)

    @lru_cache(None)
    def dfs(covered: int) -> int:
      if covered == allCovered:
        return 0

      ans = maxLines

      for i in range(n):
        if covered >> i & 1:
          continue
        for j in range(n):
          if i == j:
            continue
          # connect points[i] with points[j]
          newCovered = covered | 1 << i | 1 << j
          slope = getSlope(i, j)
          # mark points covered by this line
          for k in range(n):
            if getSlope(i, k) == slope:
              newCovered |= 1 << k
          ans = min(ans, 1 + dfs(newCovered))

      return ans

    return dfs(0)
