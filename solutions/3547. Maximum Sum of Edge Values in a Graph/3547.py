class Solution:
  def maxScore(self, n: int, edges: list[list[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n)]
    cycleSizes = []  # components where all nodes have degree 2
    pathSizes = []  # components that are not cycleSizes
    seen = set()

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    for i in range(n):
      if i in seen:
        continue
      component = self._getComponent(graph, i, seen)
      if all(len(graph[u]) == 2 for u in component):
        cycleSizes.append(len(component))
      elif len(component) > 1:
        pathSizes.append(len(component))

    for cycleSize in cycleSizes:
      ans += self._calculateScore(n - cycleSize + 1, n, True)
      n -= cycleSize

    for pathSize in sorted(pathSizes, reverse=True):
      ans += self._calculateScore(n - pathSize + 1, n, False)
      n -= pathSize

    return ans

  def _getComponent(
      self,
      graph: list[list[int]],
      start: int,
      seen: set[int],
  ) -> list[int]:
    component = [start]
    seen.add(start)
    for u in component:
      for v in graph[u]:
        if v in seen:
          continue
        component.append(v)
        seen.add(v)
    return component

  def _calculateScore(self, left: int, right: int, isCycle: bool) -> int:
    window = collections.deque([right, right])
    score = 0
    for value in range(right - 1, left - 1, -1):
      windowValue = window.popleft()
      score += windowValue * value
      window.append(value)
    return score + window[0] * window[1] * isCycle
