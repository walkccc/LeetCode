class Solution:
  def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
    n = len(passingFees)
    graph = [[] for _ in range(n)]
    minHeap = []  # (cost, time, node)
    cost = [math.inf] * n  # cost[i] := min cost to reach cities[i]
    time = [math.inf] * n  # time[i] := min cost to reach cities[i]

    for x, y, t in edges:
      graph[x].append((y, t))
      graph[y].append((x, t))

    # start with node 0 with cost = time = 0
    heapq.heappush(minHeap, (passingFees[0], 0, 0))
    cost[0] = passingFees[0]
    time[0] = 0

    while minHeap:
      currCost, currTime, x = heapq.heappop(minHeap)
      for y, pathTime in graph[x]:
        if currTime + pathTime <= maxTime:
          # go from x -> y
          newCost = currCost + passingFees[y]
          newTime = currTime + pathTime
          if cost[y] > newCost:
            cost[y] = newCost
            time[y] = newTime
            heapq.heappush(minHeap, (newCost, newTime, y))
          elif time[y] > newTime:
            time[y] = newTime
            heapq.heappush(minHeap, (newCost, newTime, y))

    return -1 if cost[-1] == math.inf else cost[-1]
