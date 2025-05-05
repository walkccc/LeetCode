class Solution:
  def minimumCost(
      self,
      n: int,
      highways: list[list[int]],
      discounts: int,
  ) -> int:
    graph = [[] for _ in range(n)]
    minHeap = [(0, 0, discounts)]  # (d, u, leftDiscounts)
    minDiscounts = {}

    for city1, city2, toll in highways:
      graph[city1].append((city2, toll))
      graph[city2].append((city1, toll))

    while minHeap:
      d, u, leftDiscounts = heapq.heappop(minHeap)
      if u == n - 1:
        return d
      if u in minDiscounts and minDiscounts[u] >= leftDiscounts:
        continue
      minDiscounts[u] = leftDiscounts
      for v, w in graph[u]:
        heapq.heappush(minHeap, (d + w, v, leftDiscounts))
        if leftDiscounts > 0:
          heapq.heappush(minHeap, (d + w // 2, v, leftDiscounts - 1))

    return -1
