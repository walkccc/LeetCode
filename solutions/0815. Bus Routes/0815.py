class Solution:
  def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
    if S == T:
      return 0

    graph = defaultdict(list)
    usedBuses = set()

    for i in range(len(routes)):
      for route in routes[i]:
        graph[route].append(i)

    ans = 0
    q = deque([S])

    while q:
      ans += 1
      for _ in range(len(q)):
        for bus in graph[q.popleft()]:
          if bus in usedBuses:
            continue
          usedBuses.add(bus)
          for nextRoute in routes[bus]:
            if nextRoute == T:
              return ans
            else:
              q.append(nextRoute)

    return -1
