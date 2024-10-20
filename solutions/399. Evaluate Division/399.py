class Solution:
  def calcEquation(
      self,
      equations: list[list[str]],
      values: list[float],
      queries: list[list[str]],
  ) -> list[float]:
    ans = []
    # graph[A][B] := A / B
    graph = collections.defaultdict(dict)

    for (A, B), value in zip(equations, values):
      graph[A][B] = value
      graph[B][A] = 1 / value

    def devide(A: str, C: str, seen: set[str]) -> float:
      """Returns A / C."""
      if A == C:
        return 1.0

      seen.add(A)

      # value := A / B
      for B, value in graph[A].items():
        if B in seen:
          continue
        res = devide(B, C, seen)  # B / C
        if res > 0:  # valid result
          return value * res  # (A / B) * (B / C) = A / C

      return -1.0  # invalid result

    for A, C in queries:
      if A not in graph or C not in graph:
        ans.append(-1.0)
      else:
        ans.append(devide(A, C, set()))

    return ans
