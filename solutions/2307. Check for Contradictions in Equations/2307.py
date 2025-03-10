class Solution:
  def checkContradictions(
      self,
      equations: list[list[str]],
      values: list[float],
  ) -> bool:
    # Convert `string` to `int` for a better perfermance.
    strToInt = {}

    for u, v in equations:
      strToInt.setdefault(u, len(strToInt))
      strToInt.setdefault(v, len(strToInt))

    graph = [[] for _ in range(len(strToInt))]
    seen = [0.0] * len(graph)

    for i, ((A, B), value) in enumerate(zip(equations, values)):
      u = strToInt[A]
      v = strToInt[B]
      graph[u].append((v, value))
      graph[v].append((u, 1 / value))

    def dfs(u: int, val: float) -> bool:
      if seen[u]:
        return abs(val / seen[u] - 1) > 1e-5

      seen[u] = val
      return any(dfs(v, val / w) for v, w in graph[u])

    for i in range(len(graph)):
      if not seen[i] and dfs(i, 1.0):
        return True

    return False
