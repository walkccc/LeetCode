class Solution:
  def countComponents(self, n: int, edges: List[List[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n)]
    seen = set()

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    def dfs(u: int, seen: Set[int]) -> None:
      for v in graph[u]:
        if v not in seen:
          seen.add(v)
          dfs(v, seen)

    for i in range(n):
      if i not in seen:
        seen.add(i)
        dfs(graph, i, seen)
        ans += 1

    return ans
