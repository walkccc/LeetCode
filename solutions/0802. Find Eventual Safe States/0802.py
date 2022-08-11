from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
    state = [State.INIT] * len(graph)

    def hasCycle(u: int) -> bool:
      if state[u] == State.VISITING:
        return True
      if state[u] == State.VISITED:
        return False

      state[u] = State.VISITING
      if any(hasCycle(v) for v in graph[u]):
        return True
      state[u] = State.VISITED

    return [i for i in range(len(graph)) if not hasCycle(i)]
