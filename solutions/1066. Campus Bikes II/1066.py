class Solution:
  def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
    def dist(p1: List[int], p2: List[int]) -> int:
      return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    @functools.lru_cache(None)
    def dp(workerIndex: int, used: int) -> int:
      """
      Returns the minimum Manhattan distances to assign bikes to
      workers[workerIndex..n), where `used` is the bitmask of the used bikes.
      """
      if workerIndex == len(workers):
        return 0
      return min((dist(workers[workerIndex], bike) + dp(workerIndex + 1, used | 1 << i)
                  for i, bike in enumerate(bikes)
                  if not used & 1 << i), default=math.inf)

    return dp(0, 0)
