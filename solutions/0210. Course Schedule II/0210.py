from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    ans = []
    graph = [[] for _ in range(numCourses)]
    state = [State.INIT] * numCourses

    for v, u in prerequisites:
      graph[u].append(v)

    def hasCycle(u: int) -> bool:
      if state[u] == State.VISITING:
        return True
      if state[u] == State.VISITED:
        return False

      state[u] = State.VISITING
      if any(hasCycle(v) for v in graph[u]):
        return True
      state[u] = State.VISITED
      ans.append(u)

      return False

    if any(hasCycle(i) for i in range(numCourses)):
      return []

    return ans[::-1]
