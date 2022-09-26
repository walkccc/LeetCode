from enum import Enum


class Color(Enum):
  WHITE = 0
  RED = 1
  GREEN = 2


class Solution:
  def isBipartite(self, graph: List[List[int]]) -> bool:
    colors = [Color.WHITE] * len(graph)

    for i in range(len(graph)):
      # already colored, do nothing
      if colors[i] != Color.WHITE:
        continue
      # colors[i] == Color.WHITE
      colors[i] = Color.RED  # always paint w/ Color.RED
      # BFS
      q = deque([i])
      while q:
        u = q.popleft()
        for v in graph[u]:
          if colors[v] == colors[u]:
            return False
          if colors[v] == Color.WHITE:
            colors[v] = Color.RED if colors[u] == Color.GREEN else Color.GREEN
            q.append(v)

    return True
