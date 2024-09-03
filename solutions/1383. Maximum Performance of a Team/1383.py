class Solution:
  # Similar to 857. Minimum Cost to Hire K Workers
  def maxPerformance(
      self,
      n: int,
      speed: list[int],
      efficiency: list[int],
      k: int,
  ) -> int:
    kMod = 1_000_000_007
    ans = 0
    speedSum = 0
    # (efficiency[i], speed[i]) sorted by efficiency[i] in descending order
    A = sorted([(e, s) for s, e in zip(speed, efficiency)], reverse=True)
    minHeap = []

    for e, s in A:
      heapq.heappush(minHeap, s)
      speedSum += s
      if len(minHeap) > k:
        speedSum -= heapq.heappop(minHeap)
      ans = max(ans, speedSum * e)

    return ans % kMod
