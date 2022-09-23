class Solution:
  def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
    ans = [set() for _ in range(n)]
    graph = [[] for _ in range(n)]
    inDegree = [0] * n

    # build graph
    for u, v in edges:
      graph[u].append(v)
      inDegree[v] += 1

    # topology
    q = deque([i for i, d in enumerate(inDegree) if d == 0])

    while q:
      for _ in range(len(q)):
        u = q.popleft()
        for v in graph[u]:
          ans[v].add(u)
          ans[v].update(ans[u])
          inDegree[v] -= 1
          if inDegree[v] == 0:
            q.append(v)

    return [sorted(i) for i in ans]
