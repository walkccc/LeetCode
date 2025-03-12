class Solution:
  def minCost(self, n: int, costs: list[list[int]]) -> int:
    INVALID_COLOR = 3

    def getValidColors(prevColor: int) -> list[int]:
      return [color for color in range(3) if color != prevColor]

    @functools.lru_cache(None)
    def minCost(i: int, prevLeftColor: int, prevRightColor: int) -> int:
      if i == len(costs) // 2:
        return 0
      res = math.inf
      for leftColor in getValidColors(prevLeftColor):
        for rightColor in getValidColors(prevRightColor):
          if leftColor == rightColor:
            continue
          leftCost = costs[i][leftColor]
          rightCost = costs[-1 - i][rightColor]
          res = min(res, leftCost + rightCost +
                    minCost(i + 1, leftColor, rightColor))
      return res

    return minCost(0, INVALID_COLOR, INVALID_COLOR)
