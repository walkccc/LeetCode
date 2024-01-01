class Solution:
  def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
    ans = [set() for _ in range(n)]
    graph = [[] for _ in range(n)]
    inDegrees = [0] * n

    # Build the graph.
    for u, v in edges:
      graph[u].append(v)
      inDegrees[v] += 1

    # Perform topological sorting.
    q = collections.deque([i for i, d in enumerate(inDegrees) if d == 0])

    while q:
      for _ in range(len(q)):
        u = q.popleft()
        for v in graph[u]:
          ans[v].add(u)
          ans[v].update(ans[u])
          inDegrees[v] -= 1
          if inDegrees[v] == 0:
            q.append(v)

    return [sorted(nodes) for nodes in ans]
