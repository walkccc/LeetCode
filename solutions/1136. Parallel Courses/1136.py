from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def minimumSemesters(self, n: int, relations: list[list[int]]) -> int:
    graph = [[] for _ in range(n)]
    states = [State.INIT] * n
    depth = [1] * n

    for u, v in relations:
      graph[u - 1].append(v - 1)

    def hasCycle(u: int) -> bool:
      if states[u] == State.VISITING:
        return True
      if states[u] == State.VISITED:
        return False
      states[u] = State.VISITING
      for v in graph[u]:
        if hasCycle(v):
          return True
        depth[u] = max(depth[u], 1 + depth[v])
      states[u] = State.VISITED
      return False

    if any(hasCycle(i) for i in range(n)):
      return -1
    return max(depth)
