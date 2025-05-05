from enum import Enum


class Color(Enum):
  WHITE = 0
  RED = 1
  GREEN = 2


class Solution:
  def isBipartite(self, graph: list[list[int]]) -> bool:
    colors = [Color.WHITE] * len(graph)

    def isValidColor(u: int, color: Color) -> bool:
      # The painted color should be same as `color`.
      if colors[u] != Color.WHITE:
        return colors[u] == color

      colors[u] = color

      # All the children should have valid colors.
      childrenColor = Color.RED if colors[u] == Color.GREEN else Color.GREEN
      return all(isValidColor(v, childrenColor) for v in graph[u])

    return all(colors[i] != Color.WHITE or isValidColor(i, Color.RED)
               for i in range(len(graph)))
