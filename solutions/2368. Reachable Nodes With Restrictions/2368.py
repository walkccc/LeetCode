class Solution:
  def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
    graph = [[] for _ in range(n)]
    seen = set(restricted)

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    def dfs(u: int) -> int:
      if u in seen:
        return 0
      seen.add(u)
      return 1 + sum(dfs(v) for v in graph[u])
      
    return dfs(0)
  