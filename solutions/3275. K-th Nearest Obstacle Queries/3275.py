class Solution:
  def resultsArray(self, queries: list[list[int]], k: int) -> list[int]:
    ans = []
    maxHeap = []

    for x, y in queries:
      heapq.heappush(maxHeap, -(abs(x) + abs(y)))
      if len(maxHeap) > k:
        heapq.heappop(maxHeap)
      ans.append(-maxHeap[0] if len(maxHeap) == k else -1)

    return ans
