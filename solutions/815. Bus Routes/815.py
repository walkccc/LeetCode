class Solution:
  def numBusesToDestination(
      self,
      routes: list[list[int]],
      source: int,
      target: int,
  ) -> int:
    if source == target:
      return 0

    graph = collections.defaultdict(list)
    usedBuses = set()

    for i in range(len(routes)):
      for route in routes[i]:
        graph[route].append(i)

    ans = 0
    q = collections.deque([source])

    while q:
      ans += 1
      for _ in range(len(q)):
        for bus in graph[q.popleft()]:
          if bus in usedBuses:
            continue
          usedBuses.add(bus)
          for nextRoute in routes[bus]:
            if nextRoute == target:
              return ans
            q.append(nextRoute)

    return -1
