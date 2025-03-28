class Solution:
  def checkIfPrerequisite(
      self,
      numCourses: int,
      prerequisites: list[list[int]],
      queries: list[list[int]],
  ) -> list[bool]:
    graph = [[] for _ in range(numCourses)]
    # isPrerequisite[i][j] := True if course i is a prerequisite of course j.
    isPrerequisite = [[False] * numCourses for _ in range(numCourses)]

    for u, v in prerequisites:
      graph[u].append(v)

    # DFS from every course.
    for i in range(numCourses):
      self._dfs(graph, i, isPrerequisite[i])

    return [isPrerequisite[u][v] for u, v in queries]

  def _dfs(self, graph: list[list[int]], u: int, used: list[bool]) -> None:
    for v in graph[u]:
      if used[v]:
        continue
      used[v] = True
      self._dfs(graph, v, used)
