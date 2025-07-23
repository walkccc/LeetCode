class Solution:
  def baseUnitConversions(self, conversions: list[list[int]]) -> list[int]:
    MOD = 1_000_000_007
    n = len(conversions) + 1
    ans = [0] * n
    ans[0] = 1
    q = collections.deque([0])
    graph = [[] for _ in range(n)]

    for u, v, factor in conversions:
      graph[u].append((v, factor))

    while q:
      u = q.popleft()
      for v, factor in graph[u]:
        ans[v] = (ans[u] * factor) % MOD
        q.append(v)

    return ans
