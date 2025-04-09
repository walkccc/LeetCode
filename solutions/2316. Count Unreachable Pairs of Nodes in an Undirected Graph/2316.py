class Solution:
  def countPairs(self, n: int, edges: list[list[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n)]
    seen = [0] * n
    unreached = n

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    for i in range(n):
      reached = self._dfs(graph, i, seen)
      unreached -= reached
      ans += unreached * reached

    return ans

  def _dfs(self, graph: list[list[int]], u: int, seen: list[bool]) -> int:
    if seen[u]:
      return 0
    seen[u] = True
    return functools.reduce(lambda subtotal, v:
                            subtotal + self._dfs(graph, v, seen), graph[u], 1)
