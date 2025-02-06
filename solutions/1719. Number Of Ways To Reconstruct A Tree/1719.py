class Solution:
  def checkWays(self, pairs: list[list[int]]) -> int:
    kMax = 501
    graph = collections.defaultdict(list)
    degrees = [0] * kMax
    connected = [[False] * kMax for _ in range(kMax)]

    for u, v in pairs:
      graph[u].append(v)
      graph[v].append(u)
      degrees[u] += 1
      degrees[v] += 1
      connected[u][v] = True
      connected[v][u] = True

    # For each node, sort its children by degrees in descending order.
    for _, children in graph.items():
      children.sort(key=lambda x: -degrees[x])

    # Find the root with a degree that equals to n - 1.
    root = next((i for i, d in enumerate(degrees) if d == len(graph) - 1), -1)
    if root == -1:
      return 0

    hasMoreThanOneWay = False

    def dfs(u: int, ancestors: list[int], seen: list[bool]) -> bool:
      """
      Returns True if each node rooted at u is connected to all of its
      ancestors.
      """
      nonlocal hasMoreThanOneWay
      seen[u] = True
      for ancestor in ancestors:
        if not connected[u][ancestor]:
          return False
      ancestors.append(u)
      for v in graph[u]:
        if seen[v]:
          continue
        if degrees[v] == degrees[u]:
          hasMoreThanOneWay = True
        if not dfs(v, ancestors, seen):
          return False
      ancestors.pop()
      return True

    if not dfs(root, [], [False] * kMax):
      return 0
    return 2 if hasMoreThanOneWay else 1
