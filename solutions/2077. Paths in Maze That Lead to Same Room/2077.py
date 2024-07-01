class Solution:
  def numberOfPaths(self, n: int, corridors: List[List[int]]) -> int:
    ans = 0
    graph = [[False] * 1001 for _ in range(n + 1)]

    for u, v in corridors:
      graph[u][v] = True
      graph[v][u] = True

    for u, v in corridors:
      for i in range(1, n + 1):
        if graph[u][i] and graph[i][v]:
          ans += 1

    return ans // 3
