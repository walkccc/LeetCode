class Solution:
  def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
    n = len(amount)
    tree = [[] for _ in range(n)]
    parent = [0] * n
    aliceDist = [-1] * n

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    # Fills `parent` and `aliceDist`.
    def dfs(u: int, prev: int, d: int) -> None:
      parent[u] = prev
      aliceDist[u] = d
      for v in tree[u]:
        if aliceDist[v] == -1:
          dfs(v, u, d + 1)

    dfs(0, -1, 0)

    # Modify amount athe path from node bob to node 0.
    # For each node,
    #   1. If Bob reaches earlier than Alice does, change the amount to 0.
    #   2. If Bob and Alice reach simultaneously, devide the amount by 2.
    u = bob
    bobDist = 0
    while u != 0:
      if bobDist < aliceDist[u]:
        amount[u] = 0
      elif bobDist == aliceDist[u]:
        amount[u] //= 2
      u = parent[u]
      bobDist += 1

    return self._getMoney(tree, 0, -1, amount)

  def _getMoney(self, tree: List[List[int]], u: int, prev: int, amount: List[int]) -> int:
    # a leaf node
    if len(tree[u]) == 1 and tree[u][0] == prev:
      return amount[u]

    maxPath = -math.inf
    for v in tree[u]:
      if v != prev:
        maxPath = max(maxPath, self._getMoney(tree, v, u, amount))

    return amount[u] + maxPath
