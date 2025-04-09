class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<bool> ans;
    vector<vector<int>> graph(numCourses);
    // isPrerequisite[i][j] := true if course i is a prerequisite of course j
    vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses));

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[0];
      const int v = prerequisite[1];
      graph[u].push_back(v);
    }

    // DFS from every course.
    for (int i = 0; i < numCourses; ++i)
      dfs(graph, i, isPrerequisite[i]);

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      ans.push_back(isPrerequisite[u][v]);
    }

    return ans;
  }

  void dfs(const vector<vector<int>>& graph, int u, vector<bool>& used) {
    for (const int v : graph[u]) {
      if (used[v])
        continue;
      used[v] = true;
      dfs(graph, v, used);
    }
  }
};
