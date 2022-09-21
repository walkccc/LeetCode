from enum import Enum


class Color(Enum):
  WHITE = 0
  RED = 1
  GREEN = 2


class Solution:
  def isBipartite(self, graph: List[List[int]]) -> bool:
    colors = [Color.WHITE] * len(graph)

    def isValidColor(u: int, color: Color) -> bool:
      # the painted color should be same as the `color`
      if colors[u] != Color.WHITE:
        return colors[u] == color

      colors[u] = color  # always paint w/ `color`

      # all children should have valid colors
      childrenColor = Color.RED if colors[u] == Color.GREEN else Color.GREEN
      return all(isValidColor(v, childrenColor) for v in graph[u])

    return all(colors[i] != Color.WHITE or isValidColor(i, Color.RED)
               for i in range(len(graph)))
