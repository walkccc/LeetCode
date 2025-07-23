class Solution:
  def assignBikes(
      self,
      workers: list[list[int]],
      bikes: list[list[int]],
  ) -> int:
    def dist(p1: list[int], p2: list[int]) -> int:
      return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    @functools.lru_cache(None)
    def dp(workerIndex: int, used: int) -> int:
      """
      Returns the minimum Manhattan distances to assign bikes to
      workers[workerIndex..n), where `used` is the bitmask of the used bikes.
      """
      if workerIndex == len(workers):
        return 0
      return min(
          (dist(workers[workerIndex],
                bike) + dp(workerIndex + 1, used | 1 << i) for i,
           bike in enumerate(bikes) if not used >> i & 1),
          default=math.inf)

    return dp(0, 0)
