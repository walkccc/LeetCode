from enum import Enum


class State(Enum):
  kInit = 0
  kVisiting = 1
  kVisited = 2


class Solution:
  def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
    state = [State.kInit] * len(graph)

    def hasCycle(u: int) -> bool:
      if state[u] == State.kVisiting:
        return True
      if state[u] == State.kVisited:
        return False

      state[u] = State.kVisiting
      if any(hasCycle(v) for v in graph[u]):
        return True
      state[u] = State.kVisited

    return [i for i in range(len(graph)) if not hasCycle(i)]
