class Solution:
  def remainingMethods(
      self,
      n: int,
      k: int,
      invocations: list[list[int]]
  ) -> list[int]:
    ans = []
    graph = [[] for _ in range(n)]

    for u, v in invocations:
      graph[u].append(v)

    q = collections.deque([k])
    seen = {k}

    while q:
      for _ in range(len(q)):
        for v in graph[q.popleft()]:
          if v not in seen:
            q.append(v)
            seen.add(v)

    for u in range(n):
      if u in seen:
        continue
      for v in graph[u]:
        if v in seen:
          return list(range(n))
      ans.append(u)

    return ans
