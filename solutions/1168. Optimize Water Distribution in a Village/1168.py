class Solution:
  def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n + 1)]
    minHeap = []  # (d, u)

    for u, v, w in pipes:
      graph[u].append((v, w))
      graph[v].append((u, w))

    # Connect virtual 0 with nodes 1 to n.
    for i, well in enumerate(wells):
      graph[0].append((i + 1, well))
      heapq.heappush(minHeap, (well, i + 1))

    mst = {0}

    while len(mst) < n + 1:
      d, u = heapq.heappop(minHeap)
      if u in mst:
        continue
      # Add the new vertex.
      mst.add(u)
      ans += d
      # Expand if possible.
      for v, w in graph[u]:
        if v not in mst:
          heapq.heappush(minHeap, (w, v))

    return ans
