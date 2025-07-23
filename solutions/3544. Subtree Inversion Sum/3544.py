class Solution:
  def subtreeInversionSum(
      self,
      edges: list[list[int]],
      nums: list[int],
      k: int
  ) -> int:
    n = len(edges) + 1
    parent = [-1] * n
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    @functools.lru_cache(None)
    def dp(u: int, stepsSinceInversion: int, inverted: bool) -> int:
      """
      Returns the maximum sum for subtree rooted at u, with
      `stepsSinceInversion` steps of inversion and `inverted` is true if the
      subtree is inverted.
      """
      num = -nums[u] if inverted else nums[u]
      negNum = -num
      for v in graph[u]:
        if v == parent[u]:
          continue
        parent[v] = u
        num += dp(v, min(k, stepsSinceInversion + 1), inverted)
        if stepsSinceInversion == k:
          negNum += dp(v, 1, not inverted)
      return max(num, negNum) if stepsSinceInversion == k else num

    return dp(0, k, False)
