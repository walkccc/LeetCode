class Solution:
  def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
    ans = []
    # graph[A][B] := A / B
    graph = collections.defaultdict(dict)

    for (A, B), value in zip(equations, values):
      graph[A][B] = value
      graph[B][A] = 1 / value

    def devide(A: str, C: str, seen: Set[str]) -> float:
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
      if A not in graph and C not in graph:
        ans.append(-1.0)
      else:
        ans.append(devide(A, C, set()))

    return ans
