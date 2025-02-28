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

    q = collections.deque([source])

    step = 1
    while q:
      for _ in range(len(q)):
        for bus in graph[q.popleft()]:
          if bus in usedBuses:
            continue
          usedBuses.add(bus)
          for nextRoute in routes[bus]:
            if nextRoute == target:
              return step
            q.append(nextRoute)
      step += 1

    return -1
