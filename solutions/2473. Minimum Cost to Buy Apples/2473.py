class Solution:
  def minCost(self, n: int, roads: List[List[int]], appleCost: List[int], k: int) -> List[int]:
    graph = [[] for _ in range(n)]

    for u, v, w in roads:
      graph[u - 1].append((v - 1, w))
      graph[v - 1].append((u - 1, w))

    def dijkstra(i: int) -> int:
      forwardCost = [math.inf] * n
      totalCost = [math.inf] * n
      forwardCost[i] = 0
      q = collections.deque([i])

      while q:
        u = q.popleft()
        for v, w in graph[u]:
          nextCost = forwardCost[u] + w
          if nextCost >= forwardCost[v]:
            continue
          forwardCost[v] = nextCost
          # Take apple at city v and return back to city i.
          totalCost[v] = (k + 1) * nextCost + appleCost[v]
          q.append(v)

      return min(appleCost[i], min(totalCost))

    return [dijkstra(i) for i in range(n)]
