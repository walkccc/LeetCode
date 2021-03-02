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

    for a, b in prerequisites:
      graph[b].append(a)

    def hasCycle(node: int) -> bool:
      if state[node] == State.VISITING:
        return True
      if state[node] == State.VISITED:
        return False

      state[node] = State.VISITING
      if any(hasCycle(child) for child in graph[node]):
        return True
      state[node] = State.VISITED
      ans.append(node)

      return False

    if any(hasCycle(i) for i in range(numCourses)):
      return []

    return ans[::-1]
