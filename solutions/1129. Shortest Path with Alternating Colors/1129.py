from enum import Enum


class Color(Enum):
  INIT = 0
  RED = 1
  BLUE = 2


class Solution:
  def shortestAlternatingPaths(
      self,
      n: int,
      redEdges: list[list[int]],
      blueEdges: list[list[int]],
  ) -> list[int]:
    ans = [-1] * n
    graph = [[] for _ in range(n)]  # graph[u] := [(v, edgeColor)]
    q = collections.deque([(0, Color.INIT)])  # [(u, prevColor)]

    for u, v in redEdges:
      graph[u].append((v, Color.RED))

    for u, v in blueEdges:
      graph[u].append((v, Color.BLUE))

    step = 0
    while q:
      for _ in range(len(q)):
        u, prevColor = q.popleft()
        if ans[u] == -1:
          ans[u] = step
        for i, (v, edgeColor) in enumerate(graph[u]):
          if v == -1 or edgeColor == prevColor:
            continue
          q.append((v, edgeColor))
          graph[u][i] = (-1, edgeColor)  # Mark (u, v) as used.
      step += 1

    return ans
