class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    ans = []
    graph = [[] for _ in range(numCourses)]
    inDegree = [0] * numCourses
    q = deque()

    # build graph
    for v, u in prerequisites:
      graph[u].append(v)
      inDegree[v] += 1

    # topology
    for i, degree in enumerate(inDegree):
      if degree == 0:
        q.append(i)

    while q:
      u = q.popleft()
      ans.append(u)
      for v in graph[u]:
        inDegree[v] -= 1
        if inDegree[v] == 0:
          q.append(v)

    return ans if len(ans) == numCourses else []
