from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
    states = [State.INIT] * len(graph)

    def hasCycle(u: int) -> bool:
      if states[u] == State.VISITING:
        return True
      if states[u] == State.VISITED:
        return False
      states[u] = State.VISITING
      if any(hasCycle(v) for v in graph[u]):
        return True
      states[u] = State.VISITED
      return False

    return [i for i in range(len(graph)) if not hasCycle(i)]
