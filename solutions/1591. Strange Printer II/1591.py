from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def isPrintable(self, targetGrid: list[list[int]]) -> bool:
    MAX_COLOR = 60
    m = len(targetGrid)
    n = len(targetGrid[0])

    # graph[u] := {v1, v2} means v1 and v2 cover u
    graph = [set() for _ in range(MAX_COLOR + 1)]

    for color in range(1, MAX_COLOR + 1):
      # Get the rectangle of the current color.
      minI = m
      minJ = n
      maxI = -1
      maxJ = -1
      for i in range(m):
        for j in range(n):
          if targetGrid[i][j] == color:
            minI = min(minI, i)
            minJ = min(minJ, j)
            maxI = max(maxI, i)
            maxJ = max(maxJ, j)

      # Add any color covering the current as the children.
      for i in range(minI, maxI + 1):
        for j in range(minJ, maxJ + 1):
          if targetGrid[i][j] != color:
            graph[color].add(targetGrid[i][j])

    states = [State.INIT] * (MAX_COLOR + 1)

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

    return not (any(hasCycle(i) for i in range(1, MAX_COLOR + 1)))
