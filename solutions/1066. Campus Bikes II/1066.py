class Solution:
  def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
    def dist(p1: List[int], p2: List[int]) -> int:
      return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    @functools.lru_cache(None)
    def dp(s: int, bikeUsed: int) -> int:
      """
      Returns the minimum distance to assign bikes j (bitmask) to workers[s..n).
      """
      if s == len(workers):
        return 0
      ans = math.inf
      for i, bike in enumerate(bikes):
        if bikeUsed >> i & 1:
          continue
        ans = min(ans, dist(workers[s], bike) + dp(s + 1, bikeUsed | 1 << i))
      return ans

    return dp(0, 0)
