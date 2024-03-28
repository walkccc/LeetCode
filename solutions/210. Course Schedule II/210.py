from enum import Enum


class State(Enum):
  kInit = 0
  kVisiting = 1
  kVisited = 2


class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    ans = []
    graph = [[] for _ in range(numCourses)]
    states = [State.kInit] * numCourses

    for v, u in prerequisites:
      graph[u].append(v)

    def hasCycle(u: int) -> bool:
      if states[u] == State.kVisiting:
        return True
      if states[u] == State.kVisited:
        return False

      states[u] = State.kVisiting
      if any(hasCycle(v) for v in graph[u]):
        return True
      states[u] = State.kVisited
      ans.append(u)

      return False

    if any(hasCycle(i) for i in range(numCourses)):
      return []

    return ans[::-1]
