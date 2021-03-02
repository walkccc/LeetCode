from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
    state = [State.INIT] * len(graph)

    def hasCycle(i: int) -> bool:
      if state[i] == State.VISITING:
        return True
      if state[i] == State.VISITED:
        return False

      state[i] = State.VISITING
      if any(hasCycle(neighbor) for neighbor in graph[i]):
        return True
      state[i] = State.VISITED

    return list(i for i in range(len(graph)) if not hasCycle(i))
