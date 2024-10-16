class Solution:
  def getAncestors(self, n: int, edges: list[list[int]]) -> list[list[int]]:
    ans = [[] for _ in range(n)]
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)

    def dfs(u: int, ancestor: int, seen: set[int]) -> None:
      seen.add(u)
      for v in graph[u]:
        if v in seen:
          continue
        ans[v].append(ancestor)
        dfs(v, ancestor, seen)

    for i in range(n):
      dfs(i, i, set())

    return ans
