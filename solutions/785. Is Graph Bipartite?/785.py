from enum import Enum


class Color(Enum):
  WHITE = 0
  RED = 1
  GREEN = 2


class Solution:
  def isBipartite(self, graph: list[list[int]]) -> bool:
    colors = [Color.WHITE] * len(graph)

    for i in range(len(graph)):
      # This node has been colored, so do nothing.
      if colors[i] != Color.WHITE:
        continue
      # Always paint red for a white node.
      colors[i] = Color.RED
      # BFS.
      q = collections.deque([i])
      while q:
        for _ in range(len(q)):
          u = q.popleft()
          for v in graph[u]:
            if colors[v] == colors[u]:
              return False
            if colors[v] == Color.WHITE:
              colors[v] = Color.RED if colors[u] == Color.GREEN else Color.GREEN
              q.append(v)

    return True
