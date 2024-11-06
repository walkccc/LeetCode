class Solution:
  def minNumberOfSeconds(
      self,
      mountainHeight: int,
      workerTimes: list[int]
  ) -> int:
    def getReducedHeight(m: int) -> int:
      """Returns the total height reduced by all workers in `m` seconds."""
      # The height `x` that a worker with working time `w` reduces in `m`
      # seconds.
      # w * (1 + 2 + ... + x) <= m
      #       (1 + x) * x / 2 <= m / w
      #   x^2 + x - 2 * m / w <= 0
      #                     x <= (-1 + sqrt(1 + 8 * m / w)) / 2
      return sum((-1 + math.sqrt(1 + 8 * m // workerTime)) // 2
                 for workerTime in workerTimes)

    r = min(workerTimes) * mountainHeight * (mountainHeight + 1) // 2
    return bisect.bisect_left(range(1, r), mountainHeight,
                              key=lambda m: getReducedHeight(m)) + 1
