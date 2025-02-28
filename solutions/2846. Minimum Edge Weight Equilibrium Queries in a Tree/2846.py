class Solution:
  def minOperationsQueries(
      self,
      n: int,
      edges: list[list[int]],
      queries: list[list[int]],
  ) -> list[int]:
    kMax = 26
    m = int(math.log2(n)) + 1
    ans = []
    graph = [[] for _ in range(n)]
    # jump[i][j] := the node you reach after jumping 2^j from i
    jump = [[0] * m for _ in range(n)]
    # count[i][j] := the count of j from root to i, where 1 <= j <= 26
    count = [[] for _ in range(n)]
    # depth[i] := the depth of i
    depth = [0] * n

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    def dfs(u: int, prev: int, d: int):
      if prev != -1:
        jump[u][0] = prev
      depth[u] = d
      for v, w in graph[u]:
        if v == prev:
          continue
        # Inherit the count from the parent.
        count[v] = count[u][:]
        # Add one to this edge.
        count[v][w] += 1
        dfs(v, u, d + 1)

    count[0] = [0] * (kMax + 1)
    dfs(0, -1, 0)

    # Calculate binary lifting.
    for j in range(1, m):
      for i in range(n):
        jump[i][j] = jump[jump[i][j - 1]][j - 1]

    def getLCA(u: int, v: int) -> int:
      """Returns the lca(u, v) via Calculate binary lifting."""
      # v is always deeper than u.
      if depth[u] > depth[v]:
        return getLCA(v, u)
      # Jump v to the same height of u.
      for j in range(m):
        if depth[v] - depth[u] >> j & 1:
          v = jump[v][j]
      if u == v:
        return u
      # Jump u and v to the node right below the lca.
      for j in range(m - 1, -1, -1):
        if jump[u][j] != jump[v][j]:
          u = jump[u][j]
          v = jump[v][j]
      return jump[v][0]

    for u, v in queries:
      lca = getLCA(u, v)
      # the number of edges between (u, v).
      numEdges = depth[u] + depth[v] - 2 * depth[lca]
      # the maximum frequency of edges between (u, v)
      maxFreq = max(count[u][j] + count[v][j] - 2 * count[lca][j]
                    for j in range(1, kMax + 1))
      ans.append(numEdges - maxFreq)

    return ans
