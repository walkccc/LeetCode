class Solution:
  def assignEdgeWeights(self, edges: list[list[int]]) -> int:
    MOD = 1_000_000_007
    n = len(edges) + 1
    graph = [[] for _ in range(n + 1)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    q = collections.deque([1])
    seen = {1}

    step = 0
    while q:
      for _ in range(len(q)):
        u = q.popleft()
        for v in graph[u]:
          if v not in seen:
            q.append(v)
            seen.add(v)
      step += 1

    return pow(2, step - 2, MOD) if step > 0 else 0
