from enum import Enum


class Color(Enum):
  WHITE = 0
  RED = 1
  GREEN = 2


class Solution:
  def possibleBipartition(self, n: int, dislikes: list[list[int]]) -> bool:
    graph = [[] for _ in range(n + 1)]
    colors = [Color.WHITE] * (n + 1)

    for u, v in dislikes:
      graph[u].append(v)
      graph[v].append(u)

    # Reduce to 785. Is Graph Bipartite?
    def isValidColor(u: int, color: Color) -> bool:
      # Always paint red for a white node.
      if colors[u] != Color.WHITE:
        return colors[u] == color

      colors[u] = color  # Always paint the node with `color`.

      # All the children should have valid colors.
      childrenColor = Color.RED if colors[u] == Color.GREEN else Color.GREEN
      return all(isValidColor(v, childrenColor) for v in graph[u])

    return all(colors[i] != Color.WHITE or isValidColor(i, Color.RED)
               for i in range(1, n + 1))
