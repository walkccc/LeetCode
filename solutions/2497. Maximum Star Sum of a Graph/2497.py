class Solution:
  def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
    n = len(vals)
    ans = -math.inf
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append((v, vals[v]))
      graph[v].append((u, vals[u]))

    for i, starSum in enumerate(vals):
      maxHeap = []
      for _, val in graph[i]:
        if val > 0:
          heapq.heappush(maxHeap, -val)
      j = 0
      while j < k and maxHeap:
        starSum -= heapq.heappop(maxHeap)
        j += 1
      ans = max(ans, starSum)

    return ans
