class Solution:
  def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
    ans = math.inf
    # workers := [(wagePerQuality, quality)] sorted by wagePerQuality
    workers = sorted((w / q, q) for q, w in zip(quality, wage))
    maxHeap = []
    qualitySum = 0

    for wagePerQuality, q in workers:
      heapq.heappush(maxHeap, -q)
      qualitySum += q
      if len(maxHeap) > k:
        qualitySum += heapq.heappop(maxHeap)
      if len(maxHeap) == k:
        ans = min(ans, qualitySum * wagePerQuality)

    return ans
