class Solution:
  def minOperationsQueries(
      self,
      n: int,
      edges: list[list[int]],
      queries: list[list[int]],
  ) -> list[int]:
    MAX = 26
    m = math.ceil(math.log2(n))
    graph = [[] for _ in range(n)]
    # jump[i][j] := the 2^j-th ancestor of i
    jump = [[0] * m for _ in range(n)]
    # depth[i] := the depth of i
    depth = [0] * n
    # count[i][j] := the count of j from root to i, where 1 <= j <= 26
    count = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    count[0] = [0] * (MAX + 1)
    self._dfs(graph, 0, -1, jump, depth, count)

    for j in range(1, m):
      for i in range(n):
        jump[i][j] = jump[jump[i][j - 1]][j - 1]

    def getMinOperations(u: int, v: int) -> int:
      """
      Returns the minimum number of operations to make the edge weight
      equilibrium between (u, v).
      """
      lca = self._getLCA(u, v, jump, depth)
      # the number of edges between (u, v).
      numEdges = depth[u] + depth[v] - 2 * depth[lca]
      # the maximum frequency of edges between (u, v)
      maxFreq = max(count[u][j] + count[v][j] - 2 * count[lca][j]
                    for j in range(1, MAX + 1))
      return numEdges - maxFreq

    return [getMinOperations(u, v) for u, v in queries]

  def _dfs(
      self,
      graph: list[list[tuple[int, int]]],
      u: int,
      prev: int,
      jump: list[list[int]],
      depth: list[int],
      count: list[list[int]]
  ) -> None:
    for v, w in graph[u]:
      if v == prev:
        continue
      jump[v][0] = u
      depth[v] = depth[u] + 1
      count[v] = count[u][:]
      count[v][w] += 1
      self._dfs(graph, v, u, jump, depth, count)

  def _getLCA(
      self,
      u: int,
      v: int,
      jump: list[list[int]],
      depth: list[int]
  ) -> int:
    """Returns the lca(u, v) by binary jump."""
    # v is always deeper than u.
    if depth[u] > depth[v]:
      return self._getLCA(v, u, jump, depth)
    # Jump v to the same height of u.
    for j in range(len(jump[0])):
      if depth[v] - depth[u] >> j & 1:
        v = jump[v][j]
    if u == v:
      return u
    # Jump u and v to the node right below the lca.
    for j in range(len(jump[0]) - 1, -1, -1):
      if jump[u][j] != jump[v][j]:
        u = jump[u][j]
        v = jump[v][j]
    return jump[u][0]
