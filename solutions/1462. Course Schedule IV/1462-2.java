class Solution {
  public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
    List<Boolean> ans = new ArrayList<>();
    // isPrerequisite[i][j] := true if course i is a prerequisite of course j
    boolean[][] isPrerequisite = new boolean[numCourses][numCourses];

    for (int[] prerequisite : prerequisites) {
      final int u = prerequisite[0];
      final int v = prerequisite[1];
      isPrerequisite[u][v] = true;
    }

    for (int k = 0; k < numCourses; ++k)
      for (int i = 0; i < numCourses; ++i)
        for (int j = 0; j < numCourses; ++j)
          isPrerequisite[i][j] =
              isPrerequisite[i][j] || (isPrerequisite[i][k] && isPrerequisite[k][j]);

    for (int[] query : queries) {
      final int u = query[0];
      final int v = query[1];
      ans.add(isPrerequisite[u][v]);
    }

    return ans;
  }
}
