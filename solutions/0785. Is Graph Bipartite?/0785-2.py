from enum import Enum


class Color(Enum):
  kWhite = 0
  kRed = 1
  kGreen = 2


class Solution:
  def isBipartite(self, graph: List[List[int]]) -> bool:
    colors = [Color.kWhite] * len(graph)

    def isValidColor(u: int, color: Color) -> bool:
      # The painted color should be same as the `color`.
      if colors[u] != Color.kWhite:
        return colors[u] == color

      colors[u] = color

      # All the children should have valid colors.
      childrenColor = Color.kRed if colors[u] == Color.kGreen else Color.kGreen
      return all(isValidColor(v, childrenColor) for v in graph[u])

    return all(colors[i] != Color.kWhite or isValidColor(i, Color.kRed)
               for i in range(len(graph)))
