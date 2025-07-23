class Solution:
  def reachableNodes(
      self,
      n: int,
      edges: list[list[int]],
      restricted: list[int],
  ) -> int:
    tree = [[] for _ in range(n)]
    seen = set(restricted)

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def dfs(u: int) -> int:
      if u in seen:
        return 0
      seen.add(u)
      return 1 + sum(dfs(v) for v in tree[u])

    return dfs(0)
