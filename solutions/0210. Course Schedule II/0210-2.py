class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    inDegree = [0] * numCourses
    graph = [[] for _ in range(numCourses)]

    # build graph
    for to, out in prerequisites:
      graph[out].append(to)
      inDegree[to] += 1

    # topology
    ans = []
    q = deque()

    for i in range(numCourses):
      if inDegree[i] == 0:
        q.append(i)

    while q:
      out = q.popleft()
      ans.append(out)
      for to in graph[out]:
        inDegree[to] -= 1
        if inDegree[to] == 0:
          q.append(to)

    return ans if len(ans) == numCourses else []
