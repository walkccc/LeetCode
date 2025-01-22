class Solution:
  def shortestPathLength(self, graph: list[list[int]]) -> int:
    n = len(graph)
    goal = (1 << n) - 1
    q = collections.deque()  # (u, state)
    seen = set()

    for i in range(n):
      q.append((i, 1 << i))

    step = 0
    while q:
      for _ in range(len(q)):
        u, state = q.popleft()
        if state == goal:
          return step
        if (u, state) in seen:
          continue
        seen.add((u, state))
        for v in graph[u]:
          q.append((v, state | 1 << v))
      step += 1

    return -1
