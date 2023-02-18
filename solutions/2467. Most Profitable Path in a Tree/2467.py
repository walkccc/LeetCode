class Solution:
  def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
    n = len(amount)
    graph = [[] for _ in range(n)]
    parent = [0] * n
    aliceDist = [-1] * n

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    # Get parent and aliceDist.
    def dfs(u: int, prev: int, d: int) -> None:
      parent[u] = prev
      aliceDist[u] = d
      for v in graph[u]:
        if aliceDist[v] == -1:
          dfs(v, u, d + 1)

    dfs(0, -1, 0)

    # Modify amount athe path from node bob to node 0.
    # For each node,
    #   - if Bob reaches earlier than Alice does, change the amount to 0.
    #   - if Bob and Alice reach simultaneously, devide the amount by 2.
    u = bob
    bobDist = 0
    while u != 0:
      if bobDist < aliceDist[u]:
        amount[u] = 0
      elif bobDist == aliceDist[u]:
        amount[u] //= 2
      u = parent[u]
      bobDist += 1

    return self._getMoney(graph, 0, -1, amount)

  def _getMoney(self, graph: List[List[int]], u: int, prev: int, amount: List[int]) -> int:
    # Leaf node.
    if len(graph[u]) == 1 and graph[u][0] == prev:
      return amount[u]

    maxPath = -math.inf
    for v in graph[u]:
      if v != prev:
        maxPath = max(maxPath, self._getMoney(graph, v, u, amount))

    return amount[u] + maxPath
