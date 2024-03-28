class Solution:
  def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
    ans = []
    # isPrerequisite[i][j] := True if course i is a prerequisite of course j.
    isPrerequisite = [[False] * numCourses for _ in range(numCourses)]

    for u, v in prerequisites:
      isPrerequisite[u][v] = True

    for k in range(numCourses):
      for i in range(numCourses):
        for j in range(numCourses):
          isPrerequisite[i][j] = isPrerequisite[i][j] or \
              (isPrerequisite[i][k] and isPrerequisite[k][j])

    return [isPrerequisite[u][v] for u, v in queries]
