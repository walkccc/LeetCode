class Solution:
  def queryConversions(
      self,
      conversions: list[list[int]],
      queries: list[list[int]]
  ) -> list[int]:
    self.MOD = 1_000_000_007
    units = self._baseUnitConversions(conversions)
    # By Fermat's little theorem.
    return [units[v] * self._modPow(units[u], self.MOD - 2) % self.MOD
            for u, v in queries]

  # Same as 3528. Unit Conversion I
  def _baseUnitConversions(self, conversions: list[list[int]]) -> list[int]:
    n = len(conversions) + 1
    res = [0] * n
    res[0] = 1
    q = collections.deque([0])
    graph = [[] for _ in range(n)]

    for u, v, factor in conversions:
      graph[u].append((v, factor))

    while q:
      u = q.popleft()
      for v, factor in graph[u]:
        res[v] = (res[u] * factor) % self.MOD
        q.append(v)

    return res

  def _modPow(self, x: int, n: int) -> int:
    if n == 0:
      return 1
    if n % 2 == 1:
      return x * self._modPow(x, n - 1) % self.MOD
    return self._modPow(x * x % self.MOD, n // 2)
