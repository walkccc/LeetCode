class Solution:
  def minimumLines(self, points: list[list[int]]) -> int:
    n = len(points)
    allCovered = (1 << n) - 1
    maxLines = n // 2 + (n & 1)

    def getSlope(p: list[int], q: list[int]) -> tuple[int, int]:
      dx = p[0] - q[0]
      dy = p[1] - q[1]
      if dx == 0:
        return (0, p[0])
      if dy == 0:
        return (p[1], 0)
      d = gcd(dx, dy)
      x = dx // d
      y = dy // d
      return (x, y) if x > 0 else (-x, -y)

    @functools.lru_cache(None)
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
          # Connect the points[i] with the points[j].
          newCovered = covered | 1 << i | 1 << j
          slope = getSlope(points[i], points[j])
          # Mark the points covered by this line.
          for k in range(n):
            if getSlope(points[i], points[k]) == slope:
              newCovered |= 1 << k
          ans = min(ans, 1 + dfs(newCovered))

      return ans

    return dfs(0)
