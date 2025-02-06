class Solution:
  def gardenNoAdj(self, n: int, paths: list[list[int]]) -> list[int]:
    ans = [0] * n  # ans[i] := 1, 2, 3, or 4
    graph = [[] for _ in range(n)]

    for x, y in paths:
      u = x - 1
      v = y - 1
      graph[u].append(v)
      graph[v].append(u)

    for u in range(n):
      used = functools.reduce(operator.or_, (1 << ans[v] for v in graph[u]), 0)
      ans[u] = next(type_
                    for type_ in range(1, 5)
                    if not (used >> type_ & 1))

    return ans
