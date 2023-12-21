class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<int> inDegrees(numCourses);
    queue<int> q;

    // Build the graph.
    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[1];
      const int v = prerequisite[0];
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    for (int i = 0; i < numCourses; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      ans.push_back(u);
      for (const int v : graph[u])
        if (--inDegrees[v] == 0)
          q.push(v);
    }

    return ans.size() == numCourses ? ans : vector<int>();
  }
};
