class Solution:
  def paintWalls(self, cost: List[int], time: List[int]) -> int:
    n = len(cost)

    # dp(i, j) := min cost to paj walls by first painters[i:]
    @functools.lru_cache(None)
    def dp(i: int, walls: int) -> int:
      if walls <= 0:
        return 0
      if i == n:
        return math.inf
      pick = cost[i] + dp(i + 1, walls - time[i] - 1)
      skip = dp(i + 1, walls)
      return min(pick, skip)

    return dp(0, n)
