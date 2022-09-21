from enum import Enum


class Color(Enum):
  WHITE = 0
  RED = 1
  GREEN = 2


class Solution:
  def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
    graph = [[] for _ in range(n + 1)]
    colors = [Color.WHITE] * (n + 1)

    for u, v in dislikes:
      graph[u].append(v)
      graph[v].append(u)

    # reduce to 785. Is Graph Bipartite?
    def isValidColor(u: int, color: Color) -> bool:
      # the painted color should be same as the `color`
      if colors[u] != Color.WHITE:
        return colors[u] == color

      colors[u] = color  # always paint w/ `color`

      # all children should have valid colors
      childrenColor = Color.RED if colors[u] == Color.GREEN else Color.GREEN
      return all(isValidColor(v, childrenColor) for v in graph[u])

    return all(colors[i] != Color.WHITE or isValidColor(i, Color.RED)
               for i in range(1, n + 1))
