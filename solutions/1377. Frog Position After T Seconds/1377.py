class Solution:
  def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
    graph = [[] for _ in range(n + 1)]
    q = deque([1])
    seen = [False] * (n + 1)
    prob = [0] * (n + 1)

    prob[1] = 1
    seen[1] = True

    for a, b in edges:
      graph[a].append(b)
      graph[b].append(a)

    for _ in range(t):
      for _ in range(len(q)):
        a = q.popleft()
        nChildren = sum(not seen[b] for b in graph[a])
        for b in graph[a]:
          if seen[b]:
            continue
          seen[b] = True
          prob[b] = prob[a] / nChildren
          q.append(b)
        if nChildren > 0:
          prob[a] = 0

    return prob[target]
