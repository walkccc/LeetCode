class Solution:
  def countRoutes(
      self,
      locations: list[int],
      start: int,
      finish: int,
      fuel: int,
  ) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, fuel: int) -> int:
      """
      Returns the number of ways to reach the `finish` city from the i-th city
      with `fuel` fuel.
      """
      if fuel < 0:
        return 0

      res = 1 if i == finish else 0
      for j in range(len(locations)):
        if j == i:
          continue
        res += dp(j, fuel - abs(locations[i] - locations[j]))
        res %= kMod

      return res

    return dp(start, fuel)
