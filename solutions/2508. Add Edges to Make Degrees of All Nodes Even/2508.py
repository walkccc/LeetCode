class Solution:
  def isPossible(self, n: int, edges: list[list[int]]) -> bool:
    graph = [set() for _ in range(n)]

    for u, v in edges:
      graph[u - 1].add(v - 1)
      graph[v - 1].add(u - 1)

    oddNodes = [i for i, neighbor in enumerate(
        graph) if len(neighbor) % 2 == 1]
    if not oddNodes:
      return True
    if len(oddNodes) == 2:
      a, b = oddNodes
      return any(a not in graph[i] and b not in graph[i] for i in range(n))
    if len(oddNodes) == 4:
      a, b, c, d = oddNodes
      return ((b not in graph[a] and d not in graph[c]) or
              (c not in graph[a] and d not in graph[b]) or
              (d not in graph[a] and c not in graph[b]))
    return False
