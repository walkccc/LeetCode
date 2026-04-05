class Solution:
  # Similar to 2846. Minimum Edge Weight Equilibrium Queries in a Tree
  def minimumWeight(
      self,
      edges: list[list[int]],
      queries: list[list[int]]
  ) -> list[int]:
    n = len(edges) + 1
    m = math.ceil(math.log2(n))
    graph = [[] for _ in range(n)]
    jump = [[0] * m for _ in range(n)]  # jump[i][j] := the 2^j-th ancestor of i
    depth = [0] * n  # depth[i] := the depth of i
    dist = [0] * n  # dist[i] := the distance from root to i

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    self._dfs(graph, 0, -1, jump, depth, dist)

    for j in range(1, m):
      for i in range(n):
        jump[i][j] = jump[jump[i][j - 1]][j - 1]

    return [(self._distance(src1, src2, jump, depth, dist) +
             self._distance(src1, dest, jump, depth, dist) +
             self._distance(src2, dest, jump, depth, dist)) // 2
            for src1, src2, dest in queries]

  def _dfs(
      self,
      graph: list[list[tuple[int, int]]],
      u: int,
      prev: int,
      jump: list[list[int]],
      depth: list[int],
      dist: list[int]
  ) -> None:
    for v, w in graph[u]:
      if v == prev:
        continue
      jump[v][0] = u
      depth[v] = depth[u] + 1
      dist[v] = dist[u] + w
      self._dfs(graph, v, u, jump, depth, dist)

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

  def _distance(
      self,
      u: int,
      v: int,
      jump: list[list[int]],
      depth: list[int],
      dist: list[int]
  ) -> int:
    """Returns the distance between u and v."""
    lca = self._getLCA(u, v, jump, depth)
    return dist[u] + dist[v] - 2 * dist[lca]
