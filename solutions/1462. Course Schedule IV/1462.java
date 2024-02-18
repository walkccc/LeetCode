class Solution {
  public boolean[] checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
    List<Boolean> ans = new ArrayList<>();
    List<Integer>[] graph = new List[numCourses];
    // isPrerequisite[i][j] := true if course i is a prerequisite of course j
    boolean[][] isPrerequisite = new boolean[numCourses][numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    for (int[] prerequisite : prerequisites) {
      final int u = prerequisite[0];
      final int v = prerequisite[1];
      graph[u].add(v);
    }

    // DFS from every course.
    for (int i = 0; i < numCourses; ++i)
      dfs(graph, i, isPrerequisite[i]);

    for (int[] query : queries) {
      final int u = query[0];
      final int v = query[1];
      ans.add(isPrerequisite[u][v]);
    }

    return ans;
  }

  public void dfs(const vector<vector<int>> &graph, int u, boolean[] used) {
    for (final int v : graph[u]) {
      if (used[v])
        continue;
      used[v] = true;
      dfs(graph, v, used);
    }
  }
}
class Solution {
  public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
    List<Boolean> ans = new ArrayList<>();
    List<Integer>[] graph = new List[numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    for (int[] prerequisite : prerequisites) {
      final int u = prerequisite[0];
      final int v = prerequisite[1];
      graph[u].add(v);
    }

    // isPrerequisite[i][j] := true if course i is a prerequisite of course j
    boolean[][] isPrerequisite = new boolean[numCourses][numCourses];

    // DFS from every course.
    for (int i = 0; i < numCourses; ++i)
      dfs(graph, i, isPrerequisite[i]);

    for (int[] query : queries) {
      final int u = query[0];
      final int v = query[1];
      ans.add(isPrerequisite[u][v]);
    }

    return ans;
  }

  public void dfs(List<Integer>[] graph, int u, boolean[] used) {
    for (final int v : graph[u]) {
      if (used[v])
        continue;
      used[v] = true;
      dfs(graph, v, used);
    }
  }
}
