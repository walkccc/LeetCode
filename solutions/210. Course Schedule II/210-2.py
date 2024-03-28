class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    ans = []
    graph = [[] for _ in range(numCourses)]
    inDegrees = [0] * numCourses
    q = collections.deque()

    # Build the graph.
    for v, u in prerequisites:
      graph[u].append(v)
      inDegrees[v] += 1

    # Perform topological sorting.
    q = collections.deque([i for i, d in enumerate(inDegrees) if d == 0])

    while q:
      u = q.popleft()
      ans.append(u)
      for v in graph[u]:
        inDegrees[v] -= 1
        if inDegrees[v] == 0:
          q.append(v)

    return ans if len(ans) == numCourses else []
