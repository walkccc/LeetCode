class Solution:
  def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
    ans = 0
    i = 0
    j = len(costs) - 1
    minHeapL = []  # First half
    minHeapR = []  # Second half

    for _ in range(k):
      while len(minHeapL) < candidates and i <= j:
        heapq.heappush(minHeapL, costs[i])
        i += 1
      while len(minHeapR) < candidates and i <= j:
        heapq.heappush(minHeapR, costs[j])
        j -= 1
      if not minHeapL:
        ans += heapq.heappop(minHeapR)
      elif not minHeapR:
        ans += heapq.heappop(minHeapL)
      # Both `minHeapL` and `minHeapR` are not empty.
      elif minHeapL[0] <= minHeapR[0]:
        ans += heapq.heappop(minHeapL)
      else:
        ans += heapq.heappop(minHeapR)

    return ans
