class Solution:
  def frogPosition(
      self,
      n: int,
      edges: list[list[int]],
      t: int,
      target: int,
  ) -> float:
    tree = [[] for _ in range(n + 1)]
    q = collections.deque([1])
    seen = [False] * (n + 1)
    prob = [0] * (n + 1)

    prob[1] = 1
    seen[1] = True

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    for _ in range(t):
      for _ in range(len(q)):
        a = q.popleft()
        nChildren = sum(not seen[b] for b in tree[a])
        for b in tree[a]:
          if seen[b]:
            continue
          seen[b] = True
          prob[b] = prob[a] / nChildren
          q.append(b)
        if nChildren > 0:
          prob[a] = 0

    return prob[target]
