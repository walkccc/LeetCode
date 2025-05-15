class Solution:
  def minimumLines(self, stockPrices: list[list[int]]) -> int:
    ans = 0

    stockPrices.sort()

    def getSlope(p: list[int], q: list[int]) -> tuple[int, int]:
      dx = p[0] - q[0]
      dy = p[1] - q[1]
      if dx == 0:
        return (0, p[0])
      if dy == 0:
        return (p[1], 0)
      d = gcd(dx, dy)
      return (dx // d, dy // d)

    for i in range(2, len(stockPrices)):
      a = getSlope(stockPrices[i - 2], stockPrices[i - 1])
      b = getSlope(stockPrices[i - 1], stockPrices[i])
      if a != b:
        ans += 1

    return ans + (len(stockPrices) > 1)
