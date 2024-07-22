class Solution:
  def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
    tree = [[] for _ in values]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def dfs(u: int, prev: int) -> None:
      if u > 0 and len(tree[u]) == 1:
        return values[u]
      childrenSum = sum(dfs(v, u)
                        for v in tree[u]
                        if v != prev)
      return min(childrenSum, values[u])

    return sum(values) - dfs(0, -1)
