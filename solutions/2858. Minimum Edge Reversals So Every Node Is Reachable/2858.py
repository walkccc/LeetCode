class Solution:
  def minEdgeReversals(self, n: int, edges: List[List[int]]) -> List[int]:
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append((v, True))  # 1 means (u -> v)
      graph[v].append((u, False))  # 0 means (v <- u)

    seen = {0}

    @functools.lru_cache(None)
    def dp(u: int) -> int:
      """
      Returns the minimum number of edge reversals so node u can reach every
      node in its subtree.
      """
      res = 0
      for v, isForward in graph[u]:
        if v in seen:
          continue
        seen.add(v)
        res += dp(v) + (0 if isForward else 1)
      return res

    ans = [0] * n
    ans[0] = dp(0)

    def dfs(u: int) -> None:
      for v, isForward in graph[u]:
        if v in seen:
          continue
        seen.add(v)
        ans[v] = ans[u] + (1 if isForward else -1)
        dfs(v)

    seen = {0}
    dfs(0)
    return ans
