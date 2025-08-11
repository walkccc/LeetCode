class Solution:
  def findShortestCycle(self, n: int, edges: list[list[int]]) -> int:
    INF = 1001
    ans = INF
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    def bfs(i: int) -> int:
      """Returns the length of the minimum cycle by starting BFS from node `i`.

      Returns `INF` if there's no cycle.
      """
      dist = [INF] * n
      q = collections.deque([i])
      dist[i] = 0
      while q:
        u = q.popleft()
        for v in graph[u]:
          if dist[v] == INF:
            dist[v] = dist[u] + 1
            q.append(v)
          elif dist[v] + 1 != dist[u]:   # v is not a parent u.
            return dist[v] + dist[u] + 1
      return INF

    ans = min(map(bfs, range(n)))
    return -1 if ans == INF else ans
