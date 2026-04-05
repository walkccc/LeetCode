class Solution:
  def connectTwoGroups(self, cost: list[list[int]]) -> int:
    # minCosts[j] := the minimum cost of connecting group2's point j
    minCosts = [min(col) for col in zip(*cost)]

    @functools.lru_cache(None)
    def dp(i: int, mask: int) -> int:
      """
      Returns the minimum cost to connect group1's points[i..n) with group2's
      points, where `mask` is the bitmask of the connected points in group2.
      """
      if i == len(cost):
        # All the points in group 1 are connected, so greedily assign the
        # minimum cost for the unconnected points of group2.
        return sum(minCost for j, minCost in enumerate(minCosts)
                   if (mask >> j & 1) == 0)
      return min(cost[i][j] + dp(i + 1, mask | 1 << j)
                 for j in range(len(cost[0])))

    return dp(0, 0)
