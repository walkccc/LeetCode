class Solution:
  def minTravelTime(
      self,
      l: int,
      n: int,
      k: int,
      position: list[int],
      time: list[int]
  ) -> int:
    prefix = list(itertools.accumulate(time))

    @functools.lru_cache(None)
    def dp(i: int, skips: int, last: int) -> int:
      """
      Returns the minimum travel time to reach the last stop from i-th stop,
      with `skips` skips remaining, and the last stop being `last`.
      """
      if i == n - 1:
        return 0 if skips == 0 else math.inf
      res = math.inf
      rate = prefix[i] - (prefix[last - 1] if last > 0 else 0)
      end = min(n - 1, i + skips + 1)
      for j in range(i + 1, end + 1):
        distance = position[j] - position[i]
        res = min(res, distance * rate + dp(j, skips - (j - i - 1), i + 1))
      return res

    return dp(0, k, 0)
