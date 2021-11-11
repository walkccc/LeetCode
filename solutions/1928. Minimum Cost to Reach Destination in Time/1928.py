class Solution:
  def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
    n = len(passingFees)

    graph = [[] for _ in range(n)]

    for x, y, time in edges:
      graph[x].append((y, time))
      graph[y].append((x, time))

    cost = [inf] * n  # cost[i] := min cost to reach cities[i]
    time = [inf] * n  # time[i] := min cost to reach cities[i]

    cost[0] = passingFees[0]
    time[0] = 0

    pq = []  # (cost, time, node)
    # start with node 0 with cost = time = 0
    heapq.heappush(pq, (cost[0], time[0], 0))

    while pq:
      currCost, currTime, x = heapq.heappop(pq)
      for y, pathTime in graph[x]:
        if currTime + pathTime <= maxTime:
          # go from x -> y
          newCost = currCost + passingFees[y]
          newTime = currTime + pathTime
          if cost[y] > newCost:
            cost[y] = newCost
            time[y] = newTime
            heapq.heappush(pq, (newCost, newTime, y))
          elif time[y] > newTime:
            time[y] = newTime
            heapq.heappush(pq, (newCost, newTime, y))

    return -1 if cost[-1] == inf else cost[-1]
