class Solution:
  def connectTwoGroups(self, cost):
    # minCosts[j] := min cost of connecting group2's point j
    minCosts = [min(col) for col in zip(*cost)]

    # dp(i, j) := min cost to connect group1's points[i:] with group2's points
    # in mask j
    @functools.lru_cache(None)
    def dp(i: int, mask: int) -> int:
      if i == len(cost):
        # All points in group 1 are connected, so greedily assign the min cost
        # for the unconnected points of group2.
        res = 0
        for j, minCost in enumerate(minCosts):
          if (mask >> j & 1) == 0:
            res += minCost
        return res

      res = math.inf
      for j in range(len(cost[0])):
        res = min(res, cost[i][j] + dp(i + 1, mask | 1 << j))
      return res

    return dp(0, 0)
