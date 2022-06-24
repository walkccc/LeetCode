from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
    graph = [[] for _ in range(numCourses)]
    state = [State.INIT] * numCourses

    for a, b in prerequisites:
      graph[b].append(a)

    def hasCycle(u: int) -> bool:
      if state[u] == State.VISITING:
        return True
      if state[u] == State.VISITED:
        return False

      state[u] = State.VISITING
      if any(hasCycle(v) for v in graph[u]):
        return True
      state[u] = State.VISITED

      return False

    return not any(hasCycle(i) for i in range(numCourses))
