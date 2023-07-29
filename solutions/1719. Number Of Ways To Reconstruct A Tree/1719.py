class Solution:
  def checkWays(self, pairs: List[List[int]]) -> int:
    kMax = 501
    graph = collections.defaultdict(list)
    degree = [0] * kMax
    connected = [[False] * kMax for _ in range(kMax)]

    for u, v in pairs:
      graph[u].append(v)
      graph[v].append(u)
      degree[u] += 1
      degree[v] += 1
      connected[u][v] = True
      connected[v][u] = True

    # For each node, sort its children by degree descendingly.
    for _, children in graph.items():
      children.sort(key=lambda a: degree[a], reverse=True)

    # Find the root with a degree equal to n - 1.
    root = next((i for i, d in enumerate(degree) if d == len(graph) - 1), -1)
    if root == -1:
      return 0

    hasMoreThanOneWay = False

    # Returns true if each node rooted at u is connected to all of its ancestors.
    def dfs(u: int, ancestors: List[int], seen: List[bool]) -> bool:
      nonlocal hasMoreThanOneWay
      seen[u] = True
      for ancestor in ancestors:
        if not connected[u][ancestor]:
          return False
      ancestors.append(u)
      for v in graph[u]:
        if seen[v]:
          continue
        if degree[v] == degree[u]:
          hasMoreThanOneWay = True
        if not dfs(v, ancestors, seen):
          return False
      ancestors.pop()
      return True

    if not dfs(root, [], [False] * kMax):
      return 0
    return 2 if hasMoreThanOneWay else 1
